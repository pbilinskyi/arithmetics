#include "arithmetics.h"
#include <cmath>
using namespace std;

BigInteger::BigInteger(string s_init) : s(s_init) {}

BigInteger& BigInteger::operator=(BigInteger const& other) {
	s = other.s;
	return *this;
}

BigInteger& BigInteger::operator=(BigInteger && other) {
	s = move(other.s);
	return *this;
}

BigInteger::BigInteger(BigInteger const& i_init) {
	*this = i_init;
}

BigInteger::BigInteger(BigInteger&& i_init) {
	*this = move(i_init);
}

BigInteger BigInteger::operator*(const BigInteger & other)
{
	return alg->multiply(*this, other);
}

void BigInteger::switchAlgorithm() noexcept
{

}

string BigInteger::get() const noexcept {
	return s;
}

int BigInteger::length() const noexcept
{
	return s.length();
}

BigInteger Naive::multiply(BigInteger const & i1, BigInteger const & i2)
{	
	bool carry = false;
	int N = i1.length(),
		M = i2.length();
	string s1 = i1.get(),
		   s2 = i2.get();
	return BigInteger(to_string(stoi(s1)*stoi(s2)));
}

template<typename T> T max(T a, T b) {
	return a > b ? a : b;
}

/*string Karatsuba::add(string s1, string s2) {
	size_t n = max(s1.length(), s2.length()) + 1;
	bool f = false;
	char* c = new char[n];
	for (size_t i = 0; i < n; ++i) {

	}

}

string Karatsuba::mult(string s1, string s2, int N, int M)
{
	if ((N == M)&&(N%2 == 0)) {
		string u1 = s1.substr(N),
			u2 = s1.substr(0, N),
			v1 = s2.substr(N),
			v2 = s2.substr(0, N);

	}
}

BigInteger Karatsuba::multiply(BigInteger const& i1, BigInteger const& i2) {
	string u = i1.get(),
		v = i2.get();
	return BigInteger(mult(u, v, u.length(), v.length()));
}
*/