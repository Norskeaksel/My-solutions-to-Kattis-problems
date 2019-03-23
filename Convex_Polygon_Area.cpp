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
		vector<int>x, y;
		int t,in;
		cin >> t;
		fori(t) {
			cin >> in;
			x.push_back(in);
			cin >> in;
			y.push_back(in);
		}
		double svar = 0;
		fori(t - 1) {
			svar += x[i] * y[i + 1]-y[i]*x[i+1];
		}
		svar += x[t-1] * y[0] - y[t-1] * x[0];
		cout << abs(svar / 2) << endl;
	}
}