#pragma once

class BigInteger {
	char* s;
public:
	BigInteger(const char*);
	BigInteger(const BigInteger&);
	BigInteger(BigInteger&&);
	BigInteger& operator=(BigInteger const &);
	BigInteger& operator=(BigInteger&&);
	~BigInteger() = default;

	BigInteger operator *(const BigInteger& other) const;
	
	//Left shift
	BigInteger operator <<(size_t) const;
	//Right shift
	BigInteger operator >>(size_t) const;

	BigInteger operator +(const BigInteger& other) const;

	bool operator==(const BigInteger& other) const;
	char* get() const noexcept;
};
