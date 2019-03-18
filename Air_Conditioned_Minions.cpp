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
struct interval {
	int start;
	int end;
	int taken=0;
};
int overlap(vector<pair<int, int>>in) {
	int svar = 1;
	int i=0;
	for (int j = 1; j < in.size(); j++) {
		if (in[j].second > in[i].first) {
			i = j;
			svar++;
		}
	}
	return svar;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> in;
	fori(n) {
		int ss, ff;
		cin >> ss>> ff;
		pair<int, int>a;
		a.first=ff;
		a.second=ss;
		in.push_back(a);
	}
	sort(in.begin(), in.end());
	cout << overlap(in);
}