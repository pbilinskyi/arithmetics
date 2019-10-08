#include "Naive.h"
#include <string>
#include <iostream>

//pre: use for multiplying only 1-digit numbers!
BigInteger Naive::multiply(BigInteger const & i1, BigInteger const & i2)
{
	std::string s1 = i1.get(),
		s2 = i2.get();
	return BigInteger(std::to_string(stoi(s1)*stoi(s2)).c_str());
}