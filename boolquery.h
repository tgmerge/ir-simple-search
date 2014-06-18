//
// Bool query module header
//   by tgmerge
//

#ifndef bool_h
#define bool_h

#include <string>
#include <vector>
#include "stdlib.h"
#include "vbcode.h"

typedef vector<int> ReverseTable;
typedef vector<int> ResultSet;
typedef vector<string> Expression;

class BoolQuery{

private:

	const int maxDocID = 21576;

public:

	VBCode coder;

public:

	// accept a bool query string, returns vector of results(maybe docIDs)
	// "this OR that" --> [ResultSet]
	ResultSet query(string queryStr);

public:

	// 分割字符串
	// usage: split("this is", ' ');
	Expression split(const std::string &s, char delim);

	// 检查token是否是运算符
	bool isOp(string token);

	// 返回token的优先级
	int priority(string op);

	// 中缀表达式->后缀表达式
	// e.g. (Expression)a AND b --> (Expression)a b AND
	Expression toRPN(Expression exp);

	// 计算后缀表达式
	// e.g. (Expression)a b AND --> (ResultSet)1 2 4 6
	ResultSet calcRPN(Expression exp);
	
	// 从decoder获取词项term的倒排索引
	// e.g. "doge" --> (ResultSet)1 2 5 8
	ReverseTable getReverseTable(string term);

	// 进行一次and, or, not计算
	// e.g. "AND", (table), (table) --> (table)1 5 7
	ReverseTable doCalc(string op, ReverseTable opA, ReverseTable opB);

	// 得到docID文档的全文
	// e.g. 12 --> (string)
	string getDoc(int docID);
};

#endif