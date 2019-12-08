#include "BigInteger.h"
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

BigInteger::BigInteger()
{
    
}


string BigInteger::subtracte(string str1, string str2) {
	int sub;
	bool p;
	string result = "";
	int n1 = str1.length(), n2 = str2.length();
	if (n2 > n1)
		swap(str1, str2);
	int n = equalize(str1, str2);

	if (str1[0] < str2[0] && n1 == n2){
		swap(str1, str2);
	}

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
		result.push_back(sub + '0');

	}

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






//string BigInteger::multiply(string number1, string number2,int n1, int n2){
//	
//	if (n1 == 0 || n2 == 0){
//		return "0";
//	}
//	if (n1 == 1 || n2==1){
//		int tmpnum= (number1[0] - '0') *(number2[0] - '0');
//		string res = to_string(tmpnum);
//		return res;
//	}
//	int n;
//	if (number1.size() != number2.size()){
//	 n= makeEqualLength(number1, number2);
//	}
//	n = number1.size();
//
//		string b = number1.substr(0, n1 / 2), a = number1.substr(n1 / 2, n1-(n1 / 2));
//		string d = number2.substr(0, n2 / 2), c = number2.substr(n2 / 2, n2-(n2 / 2));
//		string tmp1 = multiply(a, c, n1-(n1 / 2), n2-(n2/2));
//		string tmp2 = multiply(b, d, n1/ 2, n2/2);
//		string m1;
//		string m2;
//		string tmp3 ;
//		string power;
//		string var1 ;
//		string sub ;
//		string var2 ;
//		string power2;
//		string var3  ;
//		string var4  ;
//		string varfinal;
//		string tmp11;
//		string tmp22;
//		power = stpow(10, (n1 + n2) / 2);
//		
//		if (n1 < n2){
//			string powern1 = stpow(10, (n2 - n1) / 2);
//			m1 = add(multiply(a, powern1, a.size(), powern1.size()), b);
//			m2 = add(c, d);
//			string apc = multiply(a, powern1, a.size(), powern1.size());
//			tmp11 = multiply(apc, c,apc.size(),c.size());
//			tmp22 = multiply(b, d, n1 / 2, n2 / 2); 
//			tmp3 = multiply(m1, m2, m1.size(), m2.size());
//			var1 = multiply(power, tmp2, power.size(), tmp2.size());
//			sub = subtracte(tmp3, tmp11);
//			var2 = subtracte(sub, tmp22);
//			power2 = stpow(10, n1 / 2);
//			var3 = multiply(power2, var2, power2.size(), var2.size());
//			var4 = add(var3, tmp1);
//			varfinal = add(var1, var4);
//			return varfinal;
//
//		}
//		else if (n1 >= n2){
//			string powern2 = stpow(10, (n1 - n2) / 2);
//			m1 = add(multiply(a, powern2, a.size(), powern2.size()), b);
//			m2 = add(c, d);
//			string bpd = multiply(b, powern2, b.size(), powern2.size());
//			tmp11 = multiply(bpd, d, bpd.size(), d.size());
//			tmp22 = multiply(a, c, a.size(),b.size());
//			tmp3 = multiply(m1, m2, m1.size(), m2.size());
//			var1 = multiply(power, tmp2, power.size(), tmp2.size());
//			sub = subtracte(tmp3, tmp11);
//			var2 = subtracte(sub, tmp22);
//			power2 = stpow(10, n2 / 2);
//			var3 = multiply(power2, var2, power2.size(), var2.size());
//			var4 = add(var3, tmp1);
//			varfinal = add(var1, var4);
//			return varfinal;
//
//		}
//
//		
//	
//}


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
	
	if (n == 0){
		return "1";
	}
	if (n==1){
		int tmpnum = (number1[0] - '0') *(number2[0] - '0');
		string res = to_string(tmpnum);
		return res;
	}
	

	string b = number1.substr(0, (n / 2)), a = number1.substr(n / 2, n-(n / 2));
	string d = number2.substr(0, (n / 2)), c = number2.substr(n / 2, n-(n / 2));
	string m1 = multiply(a, c);
	string m2 = multiply(b, d);
	string z = multiply(add(a, b), add(c, d));
	//string power;
	string npad;
	string sub1;
	string sub2;
	//string powerover2;
	string nover2pad;
	string add1;
	string add2;
	//power = stpow(10, n);

	
	//npad = stpow(m2, n);

	//z = multiply(add(b, a), add(d, c));
	if (n % 2 == 0)
		npad = stpow(m2, n);
	else
		npad = stpow(m2, n + 1);
	sub1 = subtracte(z, m1);
	sub2 = subtracte(sub1, m2);
	//powerover2 = stpow(10, n-(n / 2));
	nover2pad = stpow(sub2, n-(n / 2));
	

	add1 = add(nover2pad, npad);
	add2 = add(add1, m1);
	return add2;

}

void BigInteger::evenize(string &str)
{
	int n = str.size();
	if ((n % 2 != 0 && n != 1) ){
		str = '0' + str;
	}
	
}

int BigInteger::equalize(string &str1, string &str2)
{
	int n1 = str1.size();
	int n2 = str2.size();
	if (n1 < n2)
	{
		for (int i = 0; i < n2 - n1; i++)
			str1 = '0' + str1;
		return str2.size();
	}
	else if (n1 > n2)
	{
		for (int i = 0; i < n1 - n2; i++)
			str2 = '0' + str2;
	}
	return str1.size();
}


string BigInteger::stpow(string base, int pow){
	string res = base;

	for (int i = 1; i <= pow; i++){
		res = res  + '0';
	}
	return res;
}


BigInteger::~BigInteger()
{
}
