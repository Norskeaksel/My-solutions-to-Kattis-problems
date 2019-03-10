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
#include <iterator>
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)

string D[20] = { "one", "two", "three", "four", "five","six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen", "fifteen",
"sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
string L[10] = { "","","","thirty","forty","fifty","sixty","seventy","eighty", "ninety" };
vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}
int main() {
	string s;
	map<string, string>mymap;
	fori(100) {
		if (i < 20) {
			int x = i + 1;
			ostringstream convert;
			convert << x;
			string str = convert.str();
			mymap[str] = D[i];
		}
		else {
			int x = i + 1;
			ostringstream convert;
			convert << x;
			string str = convert.str();
			string two = str.substr(1, 1);
			if (two != "0")
				mymap[str] = L[str[0] - '0'] + "-" + mymap[two];
			if (two == "0")
				mymap[str] = L[str[0] - '0'];
		}
	}

	while (getline(cin, s)) {
		string svar = "";
		vector<string>word = strsplit(s);
		fori(word.size()) {
			if (mymap.count(word[i])) {
				svar += mymap[word[i]] + " ";
				if (i == 0)
					svar[0] = toupper(svar[0]);
			}
			else {
				svar += word[i] + " ";
			}
		}
		/*fori(svar.size() - 2) {
			if (svar[i] == '.')
				svar[i + 2] = toupper(svar[i + 2]);
		}*/
		cout << svar.substr(0, svar.size() - 1) << endl;
	}
}