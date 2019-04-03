#include <iostream>
#include<string>
#include<algorithm>
#include <sstream>
#include<cmath>
#include <stdlib.h>   
using namespace std;
int main() {
	string upper,lower;
	cin >> upper >> lower;
	reverse(upper.begin(), upper.end());
	reverse(lower.begin(), lower.end());
	while (upper.size() < lower.size()) 
		upper += '0';
	while (lower.size() < upper.size())
		lower += '0';
	reverse(upper.begin(), upper.end());
	reverse(lower.begin(), lower.end());

	//cout << lower << endl;
	int countupper=0, countlower=0;
	for (int i = 0; i < upper.size(); i++) {
		if (upper[i] - '0' < lower[i] - '0') {
			upper[i] = '#';
			countupper++;
		}
		if (upper[i] - '0' > lower[i] - '0') {
			lower[i] = '#';
			countlower++;
		}
	}
	string ans1 = "", ans2 = "";
	if (countupper == upper.size())
		cout << "YODA\n";
	else {

		for (int i = 0; i < upper.size(); i++) {
			if (upper[i] != '#') {
				ans1 += upper[i];
			}
		}
		cout << atoi(ans1.c_str()) << endl;
	}
	if (countlower == lower.size())
		cout << "YODA\n";
	else{

		for (int i = 0; i < lower.size(); i++) {
			if (lower[i] != '#') {
				ans2 += lower[i];
			}
		}
		cout << atoi(ans2.c_str()) << endl;
	}
}