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

ll distance(ll x1, ll y1, ll x2, ll y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

void optimal(vll permutations, vector<pair<ll, ll>> city, int dist[11][11]) {
	vll ans;
	ll bestZ = 1e9;
	int from, to;
	do {
		ll cost = 0;
		int s = permutations.size() - 1;
		for (int i = -1; i < s; i++) {
			if (i == -1) {
				from = 0;
				to = permutations[0];
			}
			else {
				from = permutations[i];
				to = permutations[i + 1];
			}
			cost += dist[from][to];
		}
		int last = permutations[permutations.size() - 1];
		cost += dist[last][0];
		if (cost < bestZ) {
			ans = permutations;
			bestZ = cost;
		}
	} while (next_permutation(all(permutations)));
	cout << bestZ << endl;
	/*cout << endl;
	trav(ans) cout << i << endl;
	cout << endl;*/
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in() {
		int x, y;
		cin >> x >> y;
		int xstart, ystart;
		cin >> xstart >> ystart;
		vector<pair<ll, ll>> city;//cities x and y coordinates
		city.pb(make_pair(xstart, ystart));
		int n;
		cin >> n;
		fori(n) {
			pair<ll, ll> xy;
			cin >> xy.dx >> xy.dy;
			//if (xy.dx <= x && xy.dy <= y && xy.dx >= 1 && xy.dy >= 1) 
				city.pb(xy);
			
		}
		int dist[11][11];
		vll permutations;
		fori(city.size()) {
			if (i != 0)
				permutations.pb(i);
			forj(city.size()) {
				int d = distance(city[j].dx, city[j].dy, city[i].dx, city[i].dy);
				dist[i][j] = d;
				//cout << i<< " to "<< j <<"="<< d << endl;
			}
		}
		optimal(permutations, city, dist);
	}
}