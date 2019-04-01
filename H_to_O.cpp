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
vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}
string part(string str) {
	string parted;
	char letter;
	fori(str.size()) {
		string num;
		if (str[i] - '0' > 9) {
			if (str[i + 1] - '0' > 9) {
				parted += str[i];
				parted += " ";
				parted += "1";
				parted += " ";
			}
			else {	
				letter = str[i];
				while (i < str.size() && str[i + 1] - '0' <= 9) {
					num += str[i + 1];
					i++;
				}
				parted += letter;
				parted += " ";
				parted += num;
				parted += " ";
			}
		}
	}
	if (str[str.size() - 1] - '0' > 9)
		parted[parted.size() - 2] = '1';
	return parted;
}
int main() {
	string str, parted,other;
	int t;
	cin >> str >> t;
	map<string, int>mymap,mymap2;
	set<string>atom;
	parted = part(str);
	cin >> other;
	other = part(other);
	//fori(parted.size())cout << parted[i];
	vector<string>word = strsplit(parted);
	vector<string>word2 = strsplit(other);
	for (int i = 1; i < word.size(); i += 2) {
		int a = atoi(word[i].c_str());
		if (mymap[word[i - 1]] == 0)
			mymap[word[i - 1]] = a * t;
		else
			mymap[word[i - 1]] += a * t;
		atom.insert(word[i - 1]);
	}
	for (int i = 1; i < word2.size(); i += 2) {
		int a = atoi(word2[i].c_str());
		if (mymap2[word2[i - 1]] == 0)
			mymap2[word2[i - 1]] = a;
		else
			mymap2[word2[i - 1]] += a;
		atom.insert(word2[i - 1]);
	}
	int svar = 1e9;
	for (auto i : atom) {
		if (mymap[i] == 0) {
			svar = 0;
			break;
		}
		else if(mymap2[i]!=0){
			svar = min(svar, mymap[i] / mymap2[i]);
		}
	}
	cout << svar;
}