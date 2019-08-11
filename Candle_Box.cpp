#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	map<int, int>rageToCan;
	map<int, int>rcanToAge;
	map<int, int>tageToCan;
	map<int, int>tcanToAge;
	int r = 0, t = 0;
	for (int i = 3; i < 1000; i++) {
		if (i != 3) {
			r += i;
			rageToCan[i] = r;
			rcanToAge[r] = i;
		}
		t += i;
		tageToCan[i] = t;
		tcanToAge[t] = i;
	}
	int d, rc, tc, remove = 0;
	cin >> d >> rc >> tc;
	while (rcanToAge[rc] - tcanToAge[tc] != d) {
		remove++;
		rc--;
		tc++;
	}
	cout << remove;
}