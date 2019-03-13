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
	string str="";
	int one,two;
	cin >> one >> two;
	string in1,in2;
	cin >> in1 >> in2;
	reverse(in1.begin(), in1.end());
	fori(one){
		str += in1[i];
		if(i!=one-1)str += ".";
	}
	fori(two) {
		if(i)str += ".";
		str += in2[i];
	}
	int sec;
	cin >> sec;
	//fori(str.size()) cout << str[i];
	//cout << endl;
	str += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	
	while (sec--) {
		string temp = str;
		fori(102) {
			if(i==0)str[i] = '.';
			else str[i] = temp[i - 2];
			str[i + 2] = temp[i];
			i++;
			/*fori(str.size()) {
				if (str[i] != 'x'&& str[i] != '.')
					cout << str[i];
			}
			cout << endl;*/
		}
	}
	//cout << endl;
	fori(str.size()) {
		if(str[i]!='.'&& str[i] != 'x')
			cout << str[i]; 
	}
}