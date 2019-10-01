#include "arithmetics.h"
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
	if (N == M == 1) {
		return BigInteger(to_string(stoi(s1)*stoi(s2)));
	}
}
