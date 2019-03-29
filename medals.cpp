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
struct medals {
	string name;
	int g, s, b;
	int gs, gb, sb;
	int gsb;
};

medals values(string name,double g, double s, double b) {
	medals a;
	a.name = name;
	a.g = g;
	a.s = s;
	a.b = b;
	a.gs = g + s;
	a.gb = g + b;
	a.sb = s+b;
	a.gsb = g + s + b;
	return a;
}
bool win(medals c, vector<medals> o) {
	for (int k = -5; k < 6; k++) {
		for (int i = -5; i < 6; i++) {
			for (int j = -5; j < 6; j++) {
				double canscore = c.g*pow(10, k) + c.s*pow(10, i) + c.b*pow(10, j);
				double otherscore =0;
				for (int m = 0; m < o.size(); m++) {
					otherscore = max(otherscore, o[m].g*pow(10, k) + o[m].s*pow(10, i) + o[m].b*pow(10, j));
				}
				if ( canscore>=otherscore )
					return true;
			}
		}
		return false;
	}
}
	int main() {
		int n;
		while (cin >> n) {
			if (n == 0)
				break;
			string name;
			double g, s, b;
			vector<medals> data;
			fori(n) {
				cin >> name >> g >> s >> b;
				data.push_back(values(name, g, s, b));
			}
			bool lose = 1;
			medals canada;
			fori(n) {
				if (data[i].name == "Canada") {
					canada = data[i];
					lose = 0;
				}
			}
			if (lose)
				cout << "Canada cannot win.\n";
			else {
				bool svar = win(canada, data);
				if (!svar)
					cout << "Canada cannot win.\n";
				else {
					cout << "Canada wins!\n";
				}
			}
		}
	}