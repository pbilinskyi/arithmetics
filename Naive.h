#pragma once
#include "MultiplicationAlg.h"
#include "BigInteger.h"


class Naive : public MultiplicationAlg{
public:
	BigInteger multiply(BigInteger const& i1, BigInteger const& i2);
	BigInteger div(BigInteger const& i1, BigInteger const& i2);
};