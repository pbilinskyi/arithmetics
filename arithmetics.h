#pragma once
#include <string>
using namespace std;

class BigInteger {
	string	s;
public:
	BigInteger(string s);
	BigInteger(const BigInteger&);
	BigInteger(BigInteger&&);
	BigInteger& operator=(BigInteger const &);
	BigInteger& operator=(BigInteger&&);
	BigInteger& operator *(const BigInteger& other);
	~BigInteger() = default;

	string get() const noexcept;
};

class MultiplicationAlg {
public:
	BigInteger& multiply(BigInteger const& i1, BigInteger const& i2) = delete;
};
