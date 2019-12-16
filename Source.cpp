#include <iostream>
#include<string>
#include <fstream>
#include<vector>
#include "BigInteger.h"
using namespace std;

int main() {
	//BigInteger s;
	//ofstream Add;
	//ofstream Subtract;
	//ofstream Multiply;
	//Add.open("AddMytest.txt", ios::app);
	//Subtract.open("SubtractMytest.txt", ios::app);
	//Multiply.open("MultiplyMytest.txt", ios::app);

	//ifstream AddFile;
	//ifstream SubtractFile;
	//ifstream MultiplyFile;
	//string str;
	//vector<string> file;

	//////////////////////// ADD
	//AddFile.open("AddTestCases.txt",ios::in);

	//while (getline(AddFile, str)) {
	//	if (str!="")
	//	file.push_back(str);
	//}
	//AddFile.close();


	//int index = 1;
	//for (int i = 0; i < stoi(file[0]); i++){
	//	Add << s.add(file[index], file[index+1]) << endl << endl;
	//	index += 2;
	//}
	//file.clear();
	///////////////////////////////

	////////////////////////////SUB
	//SubtractFile.open("SubtractTestCases.txt", ios::in);

	//while (getline(SubtractFile, str)) {
	//	if (str != "")
	//		file.push_back(str);
	//}
	//SubtractFile.close();


	// index = 1;
	//for (int i = 0; i < stoi(file[0]); i++){
	//	Subtract << s.subtracte(file[index], file[index + 1]) << endl << endl;
	//	index += 2;
	//}

	//file.clear();
	/////////////////////////////

	///////////////////////Multiply
	//MultiplyFile.open("MultiplyTestCases.txt", ios::in);

	//while (getline(MultiplyFile, str)) {
	//	if (str != "")
	//		file.push_back(str);
	//}
	//MultiplyFile.close();


	//index = 1;
	//for (int i = 0; i < stoi(file[0]); i++){
	//	Multiply << s.multiply(file[index], file[index + 1]) << endl << endl;
	//	index += 2;
	//}

	//file.clear();
	///////////////////////////
	BigInteger s;

	cout << s.ModOfPower("3", "18132", "17");


	return 0;
}
