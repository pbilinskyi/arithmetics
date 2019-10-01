#pragma once
#include <stdexcept>
using namespace std;

char* substr(const char* c, size_t pos, size_t length) {
	size_t i;
	for (i = 0; (i < pos)&&(*c); ++i, ++c) {}
	if (!*c) throw invalid_argument("substr: index out of array");
	char* sub = new char[length + 1];

	for (i = 0; (i < length) && (*c); ++i, ++c) {
		sub[i] = *c;
	}
	
	if 	((!*c) && (i < length)) throw invalid_argument("substr: index out of array");

	sub[i] = '\0';
	return sub;
}

char* merge(const char* c1, const char* c2) {
	size_t N1 = 0, N2 = 0;
	while (c1[++N1]);
	while (c2[++N2]);

	size_t N = N1 + N2;
	char* c = new char[N + 1];
	size_t i = 0;
	for (; i < N1; ++i) c[i] = c1[i];
	for (; i < N; ++i) c[i] = c2[i - N1];

	c[N] = '\0';
	return c;
}

//pre: ONLY when N1 == N2
char* bitwise_addition(const char* c1, const char* c2) {
	size_t N1 = 0, N2 = 0;
	while (c1[++N1]);
	while (c2[++N2]);

	char* c = new char[N1 + N2 + 1 + 1];
	bool carry = false;
	size_t i = 0;
	while (*c1 || *c2) {
		if (carry) {
			if ((*c1 == '0') && (*c2 == '0')) {
				c[i] = '1';
				carry = 0;
			}
			if ((*c1 == '1') && (*c2 == '1')) {
				c[i] = '1';
			}
			else {
				c[i] = '0';
			}
		}
		else {
			if ((*c1 == '0') && (*c2 == '0')) {
				c[i] = 0;
			}
			if ((*c1 == '1') && (*c2 == '1')) {
				c[i] = '0';
				carry = 1;
			}
			else {
				c[i] = '1';
			}
		}
		++c1;
		++c2;
		++i;
	}
	c[i] = '\0';
	return c;
}