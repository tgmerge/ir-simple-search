#include "boolquery.h"
#include "vbcode.h"
#include <stdlib.h>

void displayUsage(string arg);
void work(string arg);

int main(int argc, char* argv[]) {

	if (argc < 2) {
		displayUsage(argv[0]);
	}
	else {
		work(argv[1]);
	}
}

void displayUsage(string arg) {
	cout << "Usage:" << endl;
	cout << "  " + arg + " [Query string]" << endl;
}

void work(string arg) {
	cout << "##query##" + arg + "##" << endl;

	BoolQuery boolModule;

	ResultSet res = boolModule.query(arg);

	cout << "##result count##" + to_string(res.size()) + "##" << endl;

	for (int i = 0; i < res.size(); i++) {
		cout << "##no##" + to_string(i) + "##id##" + to_string(res[i]) + "##" << endl;
		//cout << boolModule.getDoc(res[i]) << endl;
	}
}