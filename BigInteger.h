#pragma once
#include <string>
using namespace std;
class BigInteger
{
	
public:
	string multiply(string, string);
	int equalize(string&, string&);
	void evenize(string&);

	string subtracte(string, string);
	string add(string, string);
	string stpow(string, int);
	BigInteger();
	~BigInteger();
};

