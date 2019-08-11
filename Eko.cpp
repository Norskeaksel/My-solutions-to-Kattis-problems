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
#define in(t) int t; cin >> t; while(t--)

vector<ll> tree;
ll wood(ll h) {
	ll w = 0;
	fori(tree.size()) {
		if (tree[i] - h > 0)
			w += tree[i] - h;
	}
	return w;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n, m;
	cin >> n >> m;
	fori(n) {
		ll a;
		cin >> a;
		tree.push_back(a);
	}
	ll fail = 0, pass = 1e18;
	ll h;
	while (pass - fail > 1) {
		h = (pass + fail) / 2;
		ll w = wood(h);
		if (w < m) {
			pass = h;
		}
		else {
			fail = h;
		}
	}
	if (wood(h) >= m)
		cout << h;
	else
		cout << h - 1;
}