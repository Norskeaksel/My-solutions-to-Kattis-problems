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

ll dist[1234];

void disp(int n) {
	fori(n) {
		cout << dist[i] << " ";
	}
	cout << endl;

}
void BellmanFord(vector<pair<ll, ll>>node[1234], ll n, ll m, ll s) {
	fori(1234) {
		dist[i] = 1e9;
	}
	dist[s] = 0;

	fork(n - 1) {
		//cout << "itteration " << k << endl;
		forj(n) {
			trav(node[j]) {
				ll oldDist = dist[i.dy];
				ll newDist = dist[j] + i.dx;
				if(newDist<oldDist&&newDist<5e8)
					dist[i.dy] = newDist;
			}
			//disp(n);
		}
	}
	//Repeat to check for negatice cycles
		fork(n - 1) {
			forj(n) {
				trav(node[j]) {
					ll currentDist = dist[i.dy];
					ll newDist = dist[j] + i.dx;
					if (newDist < currentDist&&newDist<5e8)
						dist[i.dy] = -1e9;
				}
			}
		}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	while (1) {
		ll n, m, q, s;
		cin >> n >> m >> q >> s;
		if (n || m || q || s) {
			vector<pair<ll, ll>>node[1234];//distance and neighbours
			fori(m) {
				ll u, v, w;
				cin >> u >> v >> w;
				node[u].pb(make_pair(w, v));
			}
			BellmanFord(node, n, m, s);
			fori(q) {
				ll goal;
				cin >> goal;
				ll ans = dist[goal];
				if (ans == 1e9)
					cout << "Impossible\n";
				else if (ans == -1e9)
					cout << "-Infinity\n";
				else
					cout << ans << endl;
			}
			cout << endl;
		}
		else
			break;
	}
}