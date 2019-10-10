#pragma once
#include "BigInteger.h"
#include "MultiplicationAlg.h"
#include "Naive.h"

class Karatsuba : public MultiplicationAlg {
private:
	Naive naive;
public:
	BigInteger multiply(const BigInteger & i1, const BigInteger & i2);
};

