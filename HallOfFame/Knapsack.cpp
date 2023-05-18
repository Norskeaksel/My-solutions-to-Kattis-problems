#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 
#include <type_traits>

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

void backTrack(int it, int cap, vector<vll> &v, vpl &item, vll &ans) {
	if (v[it][cap] == 0)
		return;
	if (v[it][cap] == v[it - 1][cap])
		backTrack(it - 1, cap, v, item, ans);
	else {
		cap -= item[it].dy;
		ans.pb(it - 1);
		backTrack(it - 1, cap, v, item, ans);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll c, n;
	while (cin >> c >> n) {
		int OptimalValue = 0;
		vector<vll> v;
		v.resize(n + 1, vll(c + 1, 0));//item to capasity
		vpl item(1);//value and weight
		item[0] = { 0,0 };
		for (int i = 0; i < n; i++) {
			pll p;
			cin >> p.dx >> p.dy;
			item.pb(p);
		}
		for (int it = 1; it <= n; it++) {
			for (int cap = 1; cap <= c; cap++) {
				int weight = item[it].dy;
				if (weight <= cap) {
					ll a = item[it].dx;
					ll b = v[it - 1][cap - weight];
					v[it][cap] = max(v[it - 1][cap], a + b);
				}
				else
					v[it][cap] = v[it - 1][cap];
			}
		}
		/*for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= c; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}*/

		vll ans;
		backTrack(n, c, v, item, ans);
		sort(all(ans));
		cout << ans.size() << endl;
		trav(ans) {
			cout << i << " ";
		}
		cout << endl;
	}
}