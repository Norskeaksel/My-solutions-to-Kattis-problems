#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define all(v) (v).begin(),(v).end()
#define fori(n) for (int i=0;i<n;i++)

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n,a,counter=0;
	cin >> n;
	vector<int>heights,arrows;
	fori(n) {
		cin >> a;
		heights.push_back(a);
	}
	fori(n) {
		int currentHeight = heights[i];
		vector<int>::iterator it;
		it = find(all(arrows), currentHeight);
		if (it != arrows.end()) {//arrow already fired
			int index = distance(arrows.begin(), it);
			arrows[index]--;
		}
		else {
			counter++;
			arrows.push_back(currentHeight - 1);
		}
	}
	cout << counter;
}