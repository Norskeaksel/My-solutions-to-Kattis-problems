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
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0)
			break;
		vector<int>svar;
		svar.push_back(a);
		svar.push_back(b);
		svar.push_back(c);
		sort(svar.begin(), svar.end());
		if (svar[1] * svar[1] + svar[0] * svar[0] == svar[2] * svar[2])
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}