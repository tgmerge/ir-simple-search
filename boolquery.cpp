//
// Bool query module
//   by tgmerge
//

#include "boolquery.h"

ResultSet BoolQuery::query(string queryStr) {
	return doQuery(queryStr);
}


ReverseTable BoolQuery::doQuery(string queryStr) {
	/*
	͵������= =
	a = None
	b = None
	switch(scan for next word)
		case term:
			a = getRT(term)
			get op
			b = getRT(ʣ�µ����в���)
			result = doOp(a, b)
		case '(':
			a = getRT( doQuery(�����м�Ĳ���) )
			get op
			b = getRT(ʣ�µ����в���)
			result = doOp(a, b)
		case NOT:
			if '(':
				result = doNot( doQuery(�����м�Ĳ���) )
			else:
				a = getRT(term)
				result = doNot(a)
	*/
}


ReverseTable BoolQuery::getReverseTable(string term) {
	// RETURN a reverse index table from vbcode.decoder(term)
}
ReverseTable BoolQuery::doAnd(const ReverseTable& table1, const ReverseTable& table2) {
	
}


ReverseTable BoolQuery::doOr(const ReverseTable& table1, const ReverseTable& table2) {

}


ReverseTable BoolQuery::doNot(const ReverseTable& table1) {

}
