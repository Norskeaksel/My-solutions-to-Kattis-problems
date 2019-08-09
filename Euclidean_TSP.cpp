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

ld n;// airports
ld p;// operations
ld s;// optimalTour
ld v;// jetSpeed;
ld c;

ld time(ld c) {
	ld runTume = (n * pow(log2(n), c*sqrt(2))) / (p*1e9);
	ld flightTime = s * (1 + 1 / c) / v;
	return runTume + flightTime;		
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif

	cin >> n >> p >> s >> v;
	ld fail = 0, pass = 100, c;
	fori(200) {
		c = (pass + fail) / 2;
		if (time(c- 1e-6) < time(c + 1e-6)) {
			pass = c;
		}
		else {
			fail = c;
		}
	}
	cout << setprecision(20) << time(c) << " " << c;
}