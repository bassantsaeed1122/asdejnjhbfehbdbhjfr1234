#include <iostream>
#include<string>
#include <fstream>
#include<vector>
#include <chrono>
#include "BigInteger.h"
using namespace std;
using namespace std::chrono;

int main() {
	/*ofstream outtest;
	ifstream intest;

	BigInteger s;

	outtest.open("SampleMytest.txt",ios::app);
	intest.open("SampleRSA.txt", ios::in);

	vector<string> file;
	string temp;
	while (getline(intest, temp)){
		if (temp != ""){
			file.push_back(temp);
		}
	}
	temp.clear();
	intest.close();

	int index = 1;
	for (int i = 0; i < stoi(file[0]); i++)
	{
		if (stoi(file[index+3]) == 0){
			outtest << s.Encrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
		else if (stoi(file[index+3]) == 1){
			outtest << s.Decrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
	}

	outtest.close();
	file.clear();

	outtest.open("CompleteMytest.txt", ios::app);
	intest.open("TestRSA.txt", ios::in);

	while (getline(intest, temp)){
		if (temp != ""){
			file.push_back(temp);
		}
	}

	intest.close();

	index = 1;
	for (int i = 0; i < stoi(file[0]); i++)
	{
		if (stoi(file[index + 3]) == 0){
			outtest << s.Encrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
		else if (stoi(file[index + 3]) == 1){
			outtest << s.Decrypt(file[index], file[index + 1], file[index + 2]) << endl;
			index += 4;
		}
	}


	outtest.close();
	file.clear();*/
	BigInteger s;

	 
	//cout << s.Encrypt("47594980475625417724408267823112764463863576918685226363032787239910118740004860624166859668486833021538759738968887527"	,"17","12345678908765435451231232435465767657456453453465475654264325") << endl;
         // n e m
	auto start = high_resolution_clock::now();
	cout << s.Decrypt("47594980475625417724408267823112764463863576918685226363032787239910118740004860624166859668486833021538759738968887527", 
		"22397637870882549517368596622641300924171095020557753582603446902846197377658196974714575577237681892436409853219169457", 
		"41766942386500566296578237070670959299719447915305139877556131342637463900048558377157395064819754504877734317556821079") << endl <<endl;
	   auto stop = high_resolution_clock::now();
	   auto duration = duration_cast<seconds>(stop - start);
	   cout << duration.count() << endl;

	// n d EM

	return 0;  
}
