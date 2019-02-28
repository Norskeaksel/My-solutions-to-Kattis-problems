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
	vector<pair<int,int>>in;
	fori(n) {
		int a;
		cin >> a;
		pair<int, int>b;
		b.first = a;
		b.second = i;
		in.push_back(b);
	}
	sort(in.begin(), in.end());
	int svar = n;
	fori(n-1) {
		if (in[i].first == in[i + 1].first) {
			svar = min(svar, abs(in[i + 1].second - in[i].second));
		}
	}
	cout << svar;
}