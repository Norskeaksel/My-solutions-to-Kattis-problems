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
	vector<int>can,need;
	int n, m,in;
	cin >> n >> m;
	fori(n) {
		cin >> in;
		can.push_back(in);
	}
	fori(m) {
		cin >> in;
		need.push_back(in);
	}
	sort(need.begin(), need.end());
	sort(can.begin(), can.end());
	long long svar = 0;
	fori(m) {
		auto a = lower_bound(can.begin(), can.end(), need[i]);
		svar += *a - need[i];
	}
	cout << svar;
}