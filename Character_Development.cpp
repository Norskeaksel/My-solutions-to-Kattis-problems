#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif

#define ll long long
#define forx(n) for (int x=1;x<=n;x++)

ll nCr(int n,int r){
	ll ans = 1;
	int a = 1;
	for(int i=n;i>r;i--){
		ans*=i;
		ans /= a++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	for(int i=2;i<=n;i++){
		ans += nCr(n, i);
	}
	cout << ans;
}