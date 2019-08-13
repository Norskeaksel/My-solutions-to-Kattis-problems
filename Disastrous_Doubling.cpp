#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif

using ll = long long;

int main() {
	ll b = 1, t;
	cin >> t;
	int check = 1;
	ll k = (1e9 + 7);
	while(t--){
		b *= 2;
		ll e;
		cin >> e;
		b -= e;
		if(b<0&&check){
			cout << "error\n";
			exit(0);
		}
		if(abs(b)>pow(2,61)){
			b %= k;
			check = 0;
		}
	}
	cout << (b%k+k)%k;
}