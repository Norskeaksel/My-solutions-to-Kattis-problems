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
	int n, roof, in;
	cin >> n >> roof;
	vector<int>items;
	fori(n) {
		cin >> in;
		items.push_back(in);
	}
	sort(items.begin(), items.end());
	if (n < 2)
		cout << n;
	else {
		vector<int>sub = { items[0],items[1] };
		int next = 1;
		int svar = 1;
		while (sub[sub.size() - 1] + sub[sub.size() - 2] <= roof) {
			svar++;
			next++;
			if (next < n) {
				sub.push_back(items[next]);
			}
			else
				break;
		}

		cout << svar;
	}
}