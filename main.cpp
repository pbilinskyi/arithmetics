//source/repos/"3d Term"/arithmetics
#include <iostream>
#include "arithmetics.h"
#include "cstring_mng.h"

using namespace std;

int main() {
	try {
	//	cout << substr("abcdefghig", 2, 4) << endl;
	//	cout << merge("Kara", "tsuba") << endl;
		cout << bitwise_addition("101", "100") << endl;
	}
	catch (...) { cout << "exception" << endl; }

	system("pause");
	return 0;
}