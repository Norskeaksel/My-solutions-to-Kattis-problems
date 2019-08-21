#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ull = unsigned long long;
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
#define in(t) int t; cin >> t; while(t--)

bool invest(pair<ull, ull>stock, ull days) {
	ull spd = stock.dx*days;
	if (days != 0 && spd / days != stock.dx) return true;
	return  spd> stock.dy;
}
bool profit(vector< pair<ull, ull>>&assets, ull days, ull ret) {
	ull p = 0;
	fori(assets.size()) {
		ull x = assets[i].dx*days;
		if (days != 0 && x / days != assets[i].dx) return true;
		if (x- assets[i].dy < 0)abort();
		/*ld y = ld(assets[i].dy);
		ld x = ld(assets[i].dx);
		ld d = ld(days);
		ull add= ceil((x - y / d)*d - 1e-16);*/
		ull add= x - assets[i].dy;
		if (p + add < add) return true;
		p += add;
		//if (p >= ret) return true;
	}
	return p >= ret;
	//return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ull in, ret;
	cin >> in >> ret;
	vector<pair<ull, ull>>stocks;
	fori(in) {
		ull p, c;
		cin >> p >> c;
		stocks.push_back({ p,c });
	}
	ull fail = 0, pass = 1e17,ans;
	while (pass - fail > 1) {
		ull days = (pass + fail) / 2;
		vector <pair<ull, ull>>assets;
		for(auto i:stocks) {
			if (invest(i, days))
				assets.push_back(i);
		}
		if (profit(assets, days, ret)) {
			pass = days;
			ans = days;
		}
		else {
			fail = days;
		}
	}
	cout << ans;
}