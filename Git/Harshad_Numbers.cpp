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
int check(string in) {
	int sum = 0;
	fori(in.size()) {
		sum += in[i] - '0';
	}
	return sum;
}
int main() {
	int in;
	string str;
	cin >> in;
	while (1) {
		ostringstream convert;
		convert << in;
		str = convert.str();
		int sum = check(str);
		if (in%sum != 0)
			in++;
		else {
			cout << in;
			exit(0);
		}
	}
}