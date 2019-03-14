//#include<bits/stdc++.h> includerer alt, men fungerer ikke i c++
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <iomanip>
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)

int main() {
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		if (t) {
			string nouse, use;
			vector<string>pices;
			set<string>cat;
			fori(t) {
				cin >> nouse >> use;
				pices.push_back(use);
				cat.insert(use);
			}
			sort(pices.begin(), pices.end());
			//fori(t) cout << pices[i] << " ";
			vector<int>number = { 2 };
			int j = 0;
			for (int i = 1; i < t; i++) {
				if (pices[i] == pices[i - 1]) {
					number[j]++;
				}
				else {
					j++;
					number.push_back(2);
				}
			}
			int svar = 1;
			fori(number.size()) {
				if (number[i] != 0) {
					svar *= number[i];
					//cout << number[i];
				}
			}
			cout << svar - 1 << endl;
		}
		else
			cout << 0 << endl;
	}
}