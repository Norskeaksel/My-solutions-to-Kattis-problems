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
	fori(1e8);
		char EorD;
		string str, svar="";
		cin >> EorD >> str;
		int n = str.size();
		if (EorD == 'D') {
			//str += "???????????????????????????????????????????????????????????????????????????????????????????????????";
			n = str.size();
			fori(n) {
				if (str[i] - '0' > 0 && str[i] - '0' < 10) {
					int j = str[i] - '0';
					while (j--) {
						svar += str[i - 1];
					}
				}
			}
		}
		if (EorD == 'E') {
			for (int i = 1; i <= n; i++) {
				int j = i;
				char insert = '1';
				svar += str[i - 1];
				while (str[j] == str[i - 1]) {
					insert++;
					j++;
				}
				svar += insert;
				i = j;
			}

		}
		//fori(n) cout << numOfLett[i];
		//cout << endl;
		//fori(n) cout << str[i];
		fori(svar.size()) cout << svar[i];
}