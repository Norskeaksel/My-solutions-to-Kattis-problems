#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ld d, s;
	cin >> d >> s;
	ld low = 0,high=1e18;
	ld a,x;
	fori(200){
		a = (high + low) / 2;
		x = d / 2 / a;
		ld funk = a*(exp(x) + exp(-x)) / 2;
		ld check = a + s;
		if (check >= funk)
			high = a;
		else
			low = a;
	}
	ld sinh = (exp(x) -	 exp(-x)) / 2;
	cout <<setprecision(20)<< 2 * a*sinh;
}