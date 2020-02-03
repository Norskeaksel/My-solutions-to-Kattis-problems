#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	string a,substr;
	cin >> a;
	int ans=a.size();
	int org = ans;
	for(int i=0;i<a.size();i++){
		for(int j=2;i+j<a.size();j++){
			int counter = 0;
			substr = a.substr(i, j);
			for(int k=0;k+j<=a.size();k++){
				string test = a.substr(k, j);
				if (test == substr) {
					counter++;
					k += j - 1;
				}
			}
			ans = min(ans, org-counter*(j - 1)+j);
		}
	}
	cout << ans;
}