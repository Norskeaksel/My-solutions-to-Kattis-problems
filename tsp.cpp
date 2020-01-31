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

vector<pair<ll, ll>>node[1234567];//distance and nr

ld distance(ld x1, ld y1, ld x2, ld y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void nearestNeighbour(vector<pair<ld, ld>> city) {
	int nextCity = 0;
	int a = 0;
	fori(city.size()) {
		cout << nextCity << endl;
		forj(city.size()) {
			node[j][a].dx = 1e9;
		}
		auto next = min_element(all(node[nextCity]));
		a = (*next).dy;
		nextCity = (*next).dy;
	}
}
void optimal(vector<pair<ld, ld>> city) {
	vll permutations, ans;
	ld bestZ = 1e9;
	int n = city.size() - 1;
	forx(n) {
		permutations.pb(x);
	}
	do {
		ld cost = 0;
		for (int i = -1; i < n - 1; i++) {
			//trav(permutations) cout << i;
			if (i == -1) {
				int b = permutations[i + 1];
				cost += node[0][b].dx;
			}
			else
				cost += node[permutations[i]][permutations[i + 1]].dx;
		}
		if (cost < bestZ) {
			ans = permutations;
			bestZ = cost;
		}
	} while (next_permutation(all(permutations)));
	cout << 0 << endl;
	trav(ans)
		cout << i << endl;
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
			node[i].pb(make_pair(d, j));
		}
	}
	if (n < 20)
		optimal(city);
	else
		nearestNeighbour(city);
}	