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

	// �ָ��ַ���
	// usage: split("this is", ' ');
	Expression split(const std::string &s, char delim);

	// ���token�Ƿ��������
	bool isOp(string token);

	// ����token�����ȼ�
	int priority(string op);

	// ��׺���ʽ->��׺���ʽ
	// e.g. (Expression)a AND b --> (Expression)a b AND
	Expression toRPN(Expression exp);

	// �����׺���ʽ
	// e.g. (Expression)a b AND --> (ResultSet)1 2 4 6
	ResultSet calcRPN(Expression exp);
	
	// ��decoder��ȡ����term�ĵ�������
	// e.g. "doge" --> (ResultSet)1 2 5 8
	ReverseTable getReverseTable(string term);

	// ����һ��and, or, not����
	// e.g. "AND", (table), (table) --> (table)1 5 7
	ReverseTable doCalc(string op, ReverseTable opA, ReverseTable opB);

	// �õ�docID�ĵ���ȫ��
	// e.g. 12 --> (string)
	string getDoc(int docID);
};

#endif