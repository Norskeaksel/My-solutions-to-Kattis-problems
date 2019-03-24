#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool haveWon(vector<double>input) {
	for (int i = 0; i < 4; i++) {
		if (input[i])
			return false;
	}
	return true;
}
double checkState(vector<double>&input, map<vector<double>, double>&result) {
	if (haveWon(input)) 
		return 1;
	if (input[4] == 0) {
		return 0;
	}
	if (result.count(input)) {
		return result[input];
	}
	double p_rgbys[6];
	for (int i = 0; i < 5; i++) {
		if (input[i] > 0) {
			input[i]--;
			p_rgbys[i] = checkState(input, result);
			input[i]++;
		}
		if (input[i] == 0) {
			p_rgbys[i] = -1;
		}
	}
	double largest = *max_element(begin(input), end(input)-1);
	double bonusprob = 0;
	for (int i = 0; i < 4; i++) {
		if (input[i] == largest) {
			bonusprob += p_rgbys[i];
			break;
		}
	}
	p_rgbys[5] = bonusprob;
	double count = 0,kjent=0;
	for (int i = 0; i < 6; i++) {
		if (p_rgbys[i] == -1) {
			count++;
		}
		else {
			kjent += p_rgbys[i];
		}
	}
	double svar= kjent / (6 - count);
	result[input]=svar;
		return svar;
}
int main() {
	double d;
	vector<double>input;
	map<vector<double>, double>result;
	for (int i = 0; i < 5; i++) {
		cin >> d;
		input.push_back(d);
	}
	cout << checkState(input, result) << endl;
}