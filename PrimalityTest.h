#pragma once
#include "BigInteger.h"



class PrimalityTest {
public: 
	bool isPrime(const BigInteger&, const BigInteger&);
};

class FermatTest : public PrimalityTest {
public:
	bool isPrime(const BigInteger&, const BigInteger&);

};