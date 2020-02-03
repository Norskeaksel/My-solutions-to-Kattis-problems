#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;
using vpd = vector<pair<ld, ld>>;

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in() ll t; cin >> t; while(t--)
#define fin() ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

ld distance(ld x1, ld y1, ld x2, ld y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int dist[1234][1234];
int mem[1234][1234];

int tsp(int done, int p, ll& n) {
	if (done == (1 << n) - 1) {
		return dist[p][0];
	}
	int&memo = mem[done][p];
	if (memo == 0) {
		int r = 1e9;
		for (int i = 0; i < n; i++) {
			if (done >> i & 1) continue;
			r = min(r, tsp(done | 1 << i, i, n) + dist[p][i]);
		}
		memo = r;
	}
	return memo;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	vector<pair<ld, ld>> city;
	fin() {
		pair<ld, ld> xy;
		cin >> xy.dx >> xy.dy;
		city.pb(xy);
	}
	fori(city.size()) {
		forj(city.size()) {
			ll d = round(distance(city[j].dx, city[j].dy, city[i].dx, city[i].dy));
			if (d == 0)
				d = 1e9;
			dist[i][j]=d;
		}
	}
}