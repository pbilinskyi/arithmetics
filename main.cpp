//source/repos/"3d Term"/arithmetics
#include <iostream>
#include <bitset>
#include <random>
#include <ctime>
#include <list>
#include "cstring_mng.h"
#include "BigInteger.h"
#include "Naive.h"
#include "Karatsuba.h"

using namespace std;

template<typename T> void printArr(T* a, size_t N) {
	for (int i = 0; i < N; ++i) {
		cout <<"["<< i << "]: " << a[i] << " ";
	}
	cout << endl;
}

using namespace cstr;
void g(const char* s, const char* n) {
	size_t L_n = length(n),
		L_s = length(s),
		pos = L_s - L_n - 1;

	//iteration
	//54321 / 34  N1 == 2, N_s == 5 
	while(pos){
		const char* s_temp = substr(s, pos, L_n +1);
		const char* n_mult = n;
		if (compare(s_temp, n_mult) < 0) {
			--pos;
			s_temp = substr(s, pos, L_n);
		}
		size_t k = 1;

		while (subtract(s_temp, n_mult) >= 0) {

			n_mult = add(n_mult, n);
		}
		n_mult = subtract(n_mult, n);
		s = merge(substr(s, 0, pos), subtract(s_temp, n_mult));
	}
}

int main() {
	BigInteger i1("0111011"), i2("1101");
	cout << "Quotient: " << i1/i2 << endl << "Remainder: "<< i1%i2 << endl;
	system("pause");
	return 0;
}