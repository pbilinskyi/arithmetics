#pragma once
#include <string>
using namespace std;

class BigInteger;

class MultiplicationAlg {
public:
	virtual BigInteger multiply(BigInteger const& i1, BigInteger const& i2) = 0;
};

class Naive : public MultiplicationAlg {
public:
	BigInteger multiply(BigInteger const& i1, BigInteger const& i2);
};

class Karatsuba : public MultiplicationAlg{
	//string mult(string, string, int, int);
	//string add(string, string);
public:
	//BigInteger multiply(BigInteger const& i1, BigInteger const& i2);
};

class BigInteger {
	string	s;
	MultiplicationAlg* alg = new Naive;
public:
	BigInteger(string s);
	BigInteger(const BigInteger&);
	BigInteger(BigInteger&&);
	BigInteger& operator=(BigInteger const &);
	BigInteger& operator=(BigInteger&&);
	~BigInteger() = default;

	BigInteger operator *(const BigInteger& other);
	void switchAlgorithm() noexcept;
	string get() const noexcept;
	int length() const noexcept;
};

enum {

};


