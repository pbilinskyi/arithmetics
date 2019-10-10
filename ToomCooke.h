#pragma once
#include "MultiplicationAlg.h"

class ToomCooke : public MultiplicationAlg {
	BigInteger multiply(const BigInteger& i1, const BigInteger& i2);
};