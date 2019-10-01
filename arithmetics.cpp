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

string BigInteger::get() const noexcept {
	return s;
}



