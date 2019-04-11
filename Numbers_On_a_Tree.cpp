#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define fori(n) for (int i=0;i<n;i++)

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	string str;
	cin >> n >> str;
	map<char, int> sub;
	sub['L'] = 1;
	sub['R'] = 2;
	int nr = pow(2, n+1) - 1;
	fori(str.size()){
		//cout << nr << endl;
		if(str[i]=='L'){
			nr -= sub['L'];
			sub['L'] *= 2;
			sub['R'] = sub['R'] * 2 - 1;
		}
		if (str[i] == 'R') {
			nr -= sub['R'];
			sub['R'] *= 2;
			sub['L'] = sub['R'] - 1;
		}
	}
	cout << nr;
}