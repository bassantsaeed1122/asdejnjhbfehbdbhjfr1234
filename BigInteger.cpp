#include "BigInteger.h"
#include<string>
#include<sstream>
#include<cmath>
#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

BigInteger::BigInteger()
{
}


string BigInteger::subtracte(string str1, string str2) {
	int sub;
	int count = 0;
	string result = "";
	int n = equalize(str1, str2);
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {

		sub = (str1[i] - '0') - (str2[i] - '0') - carry;
		if (sub < 0) {
			sub += 10;
			carry = 1;

		}
		else {
			carry = 0;
		}
		if (sub == 0)
			count++;
		result.push_back(sub + '0');

	}
	if (count == n)
		return(result = 0 + '0');
	if (result[n - 1] == '0')
		result.erase(n - 1);
	reverse(result.begin(), result.end());
	return result;
}

string BigInteger::add(string str1, string str2) {
	int carry = 0;
	string result ="";
	int n = equalize(str1, str2);

	for (int i = n - 1; i >= 0; i--) {
		int sum = (str1[i] - '0') + (str2[i] - '0') + carry; //convert from string to int
		result.push_back(sum % 10 + '0'); //convert from int to string
		carry = sum / 10;

	}
	if (carry)
		result.push_back(carry + '0');
	reverse(result.begin(), result.end());
	return result;
}


string BigInteger::multiply(string number1, string number2){
	
	if (number1.size() == 1 && number1[0] == '1'){
		return number2;
	}
	if (number2.size() == 1 && number2[0] == '1'){
		return number1;
	}
	if (number1.size() == 1 && number1[0] == '0'){
		return "0";
	}
	if (number2.size() == 1 && number2[0] == '0'){
		return "0";
	}
	int n;

	if (number1.size() != number2.size()){
		n = equalize(number1, number2);
	}
	else{
		n = number1.size();
	}

	if (n == 1){
		int tmpnum = (number1[0] - '0') *(number2[0] - '0');
		string res = to_string(tmpnum);
		return res;
	}


	string b = number1.substr(0, (n / 2)), a = number1.substr(n / 2, n - (n / 2));
	string d = number2.substr(0, (n / 2)), c = number2.substr(n / 2, n - (n / 2));
	string m1 = multiply(a, c);
	string m2 = multiply(b, d);
	string z = multiply(add(a, b), add(c, d));
	string npad;
	string sub1;
	string nover2pad;
	string addfinal;



	npad = stpow(m2, 2 * (n - (n / 2)));
	sub1 = subtracte(z, add(m1, m2));
	nover2pad = stpow(sub1, n - (n / 2));
	addfinal = add(add(nover2pad, npad), m1);
	return addfinal.erase(0, min(addfinal.find_first_not_of('0'), addfinal.size() - 1));

}


int BigInteger::equalize(string &str1, string &str2)
{
	int n1 = str1.size();
	int n2 = str2.size();
	if (n1 < n2)
	{
		for (int i = 0; i < n2 - n1; i++)
			str1 = "0" + str1;
		return str2.size();
	}
	else if (n1 > n2)
	{
		for (int i = 0; i < n1 - n2; i++)
			str2 = "0" + str2;
	}
	return str1.size();
}


string BigInteger::stpow(string str, int n){
	string res = str;

	for (int i = 1; i <= n; i++){
		res = res  + '0';
	}
	return res;
}


BigInteger::~BigInteger()
{
}
