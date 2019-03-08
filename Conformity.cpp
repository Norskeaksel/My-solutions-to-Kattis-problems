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
	vector<vector<int>> allvec;
	forj(n){
		int course;
		vector<int>one;
		for (int i = 0; i < 5; i++) {
			cin >> course;
			one.push_back(course);
		}
		sort(one.begin(), one.end());
		allvec.push_back(one);
	}
	int max = 0;
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int test = 1;
		for (int j = i + 1; j < n; j++) {
			if (allvec[i] == allvec[j]) {
				test++;
			}
		}
		if (test > max) {
			counter = 1;
			max = test;
		}
		else if (test == max) {
			counter++;
		}
	}
	cout << max*counter;
}