#pragma once
#include "BigInteger.h"
#include "MultiplicationAlg.h"
#include "Naive.h"

class Karatsuba : public MultiplicationAlg {
private:
	Naive naive;
public:
	BigInteger multiply(BigInteger const& i1, BigInteger const& i2);
};

