//
// Bool query module header
//   by tgmerge
//

#ifndef bool_h
#define bool_h

#include <string>
#include <vector>
#include "stdlib.h"

typedef vector<long> ReverseTable;
typedef vector<long> ResultSet;

class BoolQuery{

public:

	// accept a bool query string, returns vector of results(maybe docIDs)
	ResultSet query(string queryStr);

private:

	ReverseTable doQuery(string queryStr);

	ReverseTable getReverseTable(string term);
	ReverseTable doAnd(const ReverseTable& table1, const ReverseTable& table2);
	ReverseTable doOr(const ReverseTable& table1, const ReverseTable& table2);
	ReverseTable doNot(const ReverseTable& table1);

};
#endif