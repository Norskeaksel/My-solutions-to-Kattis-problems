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

int best(vector<int>in, int start, int min) {
	int counter = 0,found=0;
	for (int i = start; i < in.size();i++) {
		if (in[i] < min) {
			return  counter;
		}
		else if (in[i] == min && found > 0) {
			return counter;
		}
		else if (in[i] == min && found == 0) {
			counter += in[i];
			found++;
		}
		else if(in[i]>min){
			counter += in[i];
		}
	}
	return counter;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, min;
		cin >> n >> min;
		vector<int>in, start;
		fori(n) {
			int a;
			cin >> a;
			in.push_back(a);
		}
		long long svar = 0;
		long long counter = 0;
		int found = 0;
		long long saved = 0;
		//fori(n) cout << in[i]<<" ";
		//cout << endl;
		fori(n) {
			if (in[i] < min) {
				svar = max(svar, counter);
				counter = 0;
			}
			else if (in[i] == min && found == 0) {
				counter += min;
				saved = counter;
				found = 1;
			}
			else if (in[i] == min && found) {
				svar = max(svar, counter);
				counter += min-saved;
				saved = counter;
			}
			else if (in[i] > min) {
				counter += in[i];
			}
		}
		svar = max(svar, counter);
		cout << svar << endl;
	}
}
/*for(int i=1;i<n;i++) {
	while (in[i] < min) {
		i++;
		if (i == n)
			break;
	}
	if(i<n)
	start.push_back(i);
	while (in[i] > min) {
		i++;
		if (i == n)
			break;
	}
}

fori(start.size()) {
	//cout << start[i]<<" ";
	svar = max(svar, best(in, start[i], min));
}*/