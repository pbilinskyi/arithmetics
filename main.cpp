//source/repos/"3d Term"/arithmetics
#include <iostream>
#include "arithmetics.h"

using namespace std;

int main() {
	BigInteger i1("12"), i2("12");
	cout << (i1 * i2).get() << endl;
	system("pause");
	return 0;
}