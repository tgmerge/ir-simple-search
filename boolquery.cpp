//
// Bool query module
//   by tgmerge
//

#include "boolquery.h"
#include <sstream>
#include <stack>

ResultSet BoolQuery::query(string queryStr) {
	Expression infex = split(queryStr, ' ');
	Expression rpn = toRPN(infex);
	ResultSet result = calcRPN(rpn);
	return result;
}


ResultSet BoolQuery::calcRPN(Expression exp) {
	stack<ReverseTable> tableStack;
	ReverseTable opA, opB;

	for (string token : exp) {
		if (isOp(token)) {
			opA = tableStack.top();
			tableStack.pop();
			if (token != "NOT") {
				opB = tableStack.top();
				tableStack.pop();
			}
			tableStack.push(doCalc(token, opA, opB));
		}
		else {
			ReverseTable tmp = getReverseTable(token);
			tableStack.push(tmp);
		}
	}

	return tableStack.top();
}


ReverseTable BoolQuery::getReverseTable(string term) {
	return(coder.decoder(term));
}


ReverseTable BoolQuery::doCalc(string op, ReverseTable opA, ReverseTable opB) {
	ReverseTable result;
	int iA = 0, iB = 0;
	if (op == "AND") {
		while (iA < opA.size() && iB < opB.size()) {
			if (opA[iA] == opB[iB]) {
				result.push_back(opA[iA]);
				iA++; iB++;
			}
			else
				if (opA[iA] < opB[iB]) iA++; else iB++;
		}
	}
	else if (op == "OR") {
		while (iA < opA.size() || iB < opB.size()) {
			if (iA >= opA.size() && iB >= opB.size()) {
				break;
			}
			else if (iA < opA.size() && iB < opB.size() && opA[iA] == opB[iB]) {
				result.push_back(opA[iA]);
				iA++;
				iB++;
			}
			else if (iA < opA.size() && (iB >= opB.size() || opA[iA] < opB[iB])) {
				result.push_back(opA[iA]);
				iA++;
			}
			else if (iB < opB.size() && (iA >= opA.size() || opA[iA] > opB[iB])) {
				result.push_back(opB[iB]);
				iB++;
			}
		}
	}
	else if (op == "NOT") {
		for (int i = 1, iA = 0; i <= maxDocID; i++) {
			if (opA[iA] != i) {
				result.push_back(i);
			}
			else if (iA < opA.size()-1) {
				iA++;
			}
		}
	}
	return result;
}


Expression BoolQuery::toRPN(Expression exp) {
	stack<string> tmpStack;
	Expression rpn;

	for (string token : exp) {
		if (token == "(") {
			tmpStack.push(token);
		}
		else if (token == ")") {
			while (tmpStack.top() != "(") {
				rpn.push_back(tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.pop();
		}
		else if (isOp(token)) {
			while (!tmpStack.empty() && priority(token) <= priority(tmpStack.top())) {
				rpn.push_back(tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push(token);
		}
		else { // token is a term
			rpn.push_back(token);
		}
	}
	while (!tmpStack.empty()) {
		rpn.push_back(tmpStack.top());
		tmpStack.pop();
	}

	return rpn;
}


bool BoolQuery::isOp(string token) {
	return (token == "AND" || token == "OR" || token == "NOT");
}


int BoolQuery::priority(string op) {
	if (op == "OR")  return 0;
	if (op == "AND") return 1;
	if (op == "NOT") return 2;
	if (op == "(")   return -1;
}


vector<string> BoolQuery::split(const std::string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (std::getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

string BoolQuery::getDoc(int docID) {
	ifstream file("Reuters\\" + to_string(docID) + ".html");
	stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}
