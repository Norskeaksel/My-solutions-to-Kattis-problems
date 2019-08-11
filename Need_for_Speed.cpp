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

int n, t;
ld time(ld c, vector<ld>&d, vector<ld>&v){
	ld t=0;
	fori(n){
		if (v[i] + c <= 0)
			return 1e9;
		t += d[i] / (v[i]+c);
	}
	return t;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	cin >> n >> t;
	vector<ld>distance, speed;
	fori(n){
		int d,s;
		cin >> d >> s;
		distance.push_back(d);
		speed.push_back(s);
	}
	ld fail = -1e9,pass=1e9,c;
	fori(200){
		c = (pass + fail) / 2;
		ld ct = time(c, distance, speed);
		if(ct>t){
			fail = c;
		}
		else{
			pass = c;
		}
	}
	cout << setprecision(20)<<c;
}