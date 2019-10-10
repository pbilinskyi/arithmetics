//source/repos/"3d Term"/arithmetics
#include <iostream>
#include <bitset>
#include <random>
#include <ctime>
#include <list>
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


void f() {
	BigInteger U("100000001111111100000000111111110000000011111111"), V("000110001111111100011000111111110001100011111111"), res("");
	size_t N = 40;
	int k = 1,
		q1 = 16, q0 = q1,
		r1 = 4, r0 = r1,
		Q = 4, R = 2;
	while (q0 + q1 < N) {
		++k;
		Q += R;
		R = (R + 1)*(R + 1) <= Q ? R + 1 : R;
		q0 = q1; r0 = r1;
		q1 = pow(2, Q);
		r1 = pow(2, R);
		cout << " qk = " << q1 << " rk = " << r1 << endl;
	}

	--k;
	if (k == 0) {
		Karatsuba kara;
		res = kara.multiply(U, V);
	}

	else {
		size_t r = r1, q = q1, p = q0 + q1;
		//ділимо на r + 1 частин U
		list<BigInteger> Uj, Vj, U_segm, V_segm;

		for (int i = r; i >= 0; --i) {
			BigInteger Ui(cstr::substrUnlim(U.get(), i*q, q));
			BigInteger Vi(cstr::substrUnlim(V.get(), i*q, q));
			//printf("U_%d = %s\tV_%d = %s\n", i, Ui.get(), i, Vi.get());
			U_segm.push_back(Ui);
			V_segm.push_back(Vi);
		}
	}
}

void g() {
	BigInteger U("10101011"), V("00110011"), res("");
	int r = 3, q = 2;

	list<BigInteger> Uj, Vj, U_segm, V_segm;
	for (int i = r; i >= 0; --i) {
		BigInteger Ui(cstr::substrUnlim(U.get(), i*q, q));
		BigInteger Vi(cstr::substrUnlim(V.get(), i*q, q));
		U_segm.push_back(Ui);
		V_segm.push_back(Vi);
	}

	//segmentation - split into r + 1 parts with q bits 
	BigInteger j = "0", U_temp("0"), V_temp("0");
	for (size_t i = 0; i <= 2 * r; ++i) {
		U_temp = BigInteger("0");
		for (list<BigInteger>::iterator it = U_segm.begin(); it != U_segm.end(); ++it) {
			U_temp = (U_temp * j) + (*it);
			cout << U_temp.get() << endl;
		}

		V_temp = BigInteger("0");
		for (list<BigInteger>::iterator it = V_segm.begin(); it != V_segm.end(); ++it) {
			V_temp = (V_temp * j) + (*it);
			cout << V_temp.get() << endl;
		}

		++j;
	}
	//multiply segments 
}

int main() {
	//default MultiplicationAlg - Karatsuba
	//BigInteger i1("0111"), i2("101");
	//cout << (i1*i2).get() << endl;
	
	g();
	//Karatsuba kara
	//BigInteger i1("0"), i2("01");
	//cout << i1.get()<< endl <<kara.multiply(i1, i2).get() << endl;
	system("pause");
	return 0;
}