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
int matches(string str1, string str2) {
	int m = 0;
	fori(str1.size()) {
		if (str1[i] == str2[i])
			m++;
	}
	return m;
}
int main() {
	int f;
	cin >> f;
	string str1, str2;
	cin >> str1 >> str2;
	int m = matches(str1, str2);
	int svar = 0;
	if (m <= f) {
		svar = m+str1.size()-f;
	}
	else {
		svar = str1.size() + f;
		fori(str1.size())
			if (str1[i] == str2[i]) {
				svar--;
			}
	}
	cout << svar;
}