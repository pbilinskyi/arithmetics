//source/repos/"3d Term"/arithmetics
#include <iostream>
#include <bitset>
#include <random>
#include <ctime>
#include "Random.h"
#include "cstring_mng.h"
#include "BigInteger.h"
#include "Naive.h"
#include "Karatsuba.h"

using namespace std;

void testAddition() {
	srand(time(0));

	for (int i = 0; i < 10; ++i) {
		int i1 = static_cast<int>(rand() % 256),
			i2 = static_cast<int>(rand() % 256);

		cout << "I1:      " << i1 << '\t' << bitset<8>(i1) << endl;
		cout << "I2:      " << i2 << '\t' << bitset<8>(i2) << endl;
		cout << "I1 + I2: " << i1 + i2 << '\t' << cstr::add(bitset<8>(i1).to_string().c_str(), bitset<8>(i2).to_string().c_str()) << endl;
	}
}


int main() {
	//default MultiplicationAlg - Karatsuba
	BigInteger i1("0111"), i2("101");
	cout << (i1*i2).get() << endl;
	system("pause");
	return 0;
}