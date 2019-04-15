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
	int taken = 0;
};
long long overlap(vector<long long>in,long long c,long long k) {
	long long svar = 1;
	long long currentcap = 0;
	long long i = 0;
	for (long long j = 1; j < in.size(); j++) {
		currentcap++;
		if (abs(in[j]-in[i])> k ||currentcap==c) {
			svar++;
			currentcap = 0;
			i = j;
		}
	}
	return svar;
}
int main() {
	long long s,c,k;
	cin >> s>>c>>k;
	vector<long long> in;
	fori(s) {
		long long x;
		cin >> x;
		in.push_back(x);
	}
	sort(in.begin(), in.end());
	cout << overlap(in,c,k);
}