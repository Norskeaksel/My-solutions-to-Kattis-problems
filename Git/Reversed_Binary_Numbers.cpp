#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int tall,a,svar=0;
	vector<int> utskrift;
	cin >> tall;
	while (tall!=0){
		if (tall % 2 == 0) {
			a = 0;
			tall = tall / 2;
		}
		else
		{
			a = 1;
			tall = (tall-1)/2;
		}
		utskrift.push_back(a);
	}
	for (int i = 0; i < utskrift.size(); i++) {
		svar += pow(utskrift[i]*2, utskrift.size()-i-1);
}
	cout << endl << svar << endl;
}