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
	偷懒做法= =
	a = None
	b = None
	switch(scan for next word)
		case term:
			a = getRT(term)
			get op
			b = getRT(剩下的所有部分)
			result = doOp(a, b)
		case '(':
			a = getRT( doQuery(括号中间的部分) )
			get op
			b = getRT(剩下的所有部分)
			result = doOp(a, b)
		case NOT:
			if '(':
				result = doNot( doQuery(括号中间的部分) )
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
