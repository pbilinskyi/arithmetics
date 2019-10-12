#include "Naive.h"
#include "cstring_mng.h"
#include <string>
#include <iostream>
#include <bitset>

//pre: use for multiplying only 1-digit numbers!
BigInteger Naive::multiply(BigInteger const & i1, BigInteger const & i2)
{
	std::string s1 = i1.get(),
		s2 = i2.get();
	return BigInteger(std::to_string(stoi(s1)*stoi(s2)).c_str());
}

BigInteger Naive::div(BigInteger const & i1, BigInteger const & i2)
{
	std::string s1 = cstr::invert(i1.get()),
				s2 = cstr::invert(i2.get());
	int x1 = std::stoi(s1, nullptr, 2),
		x2 = std::stoi(s2, nullptr, 2);

	return BigInteger(cstr::decToBin(x1 / x2));
}
