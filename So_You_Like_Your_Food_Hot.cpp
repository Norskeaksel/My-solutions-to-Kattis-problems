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
	double cc, aa, bb;
	cin >> cc >> aa >> bb;
	long long c = cc *100+0.5 ;
	long long a = aa * 100+0.5;
	long long b = bb * 100 + 0.5;
	int check = 0;
	for (long long i = 0; i*a <= c; i++) {
		if ((c - a * i) % b == 0 && (c - a * i) >= 0) {
			check = 1;
			cout << i << " " << ((c - a * i) / b) << endl;
		}
	}
	if (!check)
		cout << "none\n";
}