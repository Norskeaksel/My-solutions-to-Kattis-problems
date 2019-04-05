#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <cmath>
using namespace std;
string intToBin(long long n){
	string r;
	while (n != 0) {
		if (n % 2)
			r = "1" + r; 
		else
			r = "0" + r;
		n /= 2; 
	}
	return r;
}
vector<long long> splitNum(long long n) {
	vector<long long> svar;
	for (int j = 9; j >= 0; j--)
		svar.push_back(n / pow(10, j));
	return svar;
}
int checkones(string str) {
	int svar = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1')
			svar++;
	}
	return svar;
}
void actualFunction() {
	int t;
	cin >> t;
	long long n;
	for (int i = 0; i < t; i++) {
		int realans=0;
		vector<int>numOf1;
		cin >> n;
		vector<long long>numbers = splitNum(n);
		string binary;
			for (int x = 0; x < numbers.size(); x++) {
				binary=intToBin(numbers[x]);
				numOf1.push_back(checkones(binary));
			}
		for (int i = 0; i < numOf1.size(); i++) {
			if (numOf1[i] > realans)
				realans = numOf1[i];
		}
		cout << realans << endl;
	}
}
int main() {
	actualFunction();
}
/*ostringstream convert;
		convert << n;
		string str = convert.str();
		vector<string>splitNum = stringToBin(str),svar;
		for (int x = 0; x < splitNum.size(); x++) {
		long long counter = 0;
		long long  currentNum=stoi(splitNum[x]);
		for (int j = 0; j < binstr.size(); j++) {
			if (binstr[j] == '1')
				counter++;
		}
		svar.push_back(counter);*/
