#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h>
using namespace std;
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;
using vpd = vector<pair<ld, ld>>;
using vs = vector<string>;

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
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

void dfs(int done[], vll node[], int index,int &change) {//Trenger & for å endre input
	if (done[index] == 0)
		change = 1;
	done[index] = 1;//vi er ferdig med nåværende node
	for (int i : node[index])//for alle naboer til nåværedne node
		if (done[i] == 0) {//dersom vi ikke er ferdige med dem
			change = 1;
			dfs(done, node, i,change);
		}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	cin >> n;
	while (n--) {
		int r;
		cin >> r;
		vll city[1234];
		vll exist;
		fori(r) {
			exist.pb(i);
		}
		in() {
			int b, c;
			cin >> b >> c;
			city[b].pb(c);
			city[c].pb(b);
		}
		int ans = -1;
		int done[1234];
		fill_n(done, 1234, 0);
		trav(exist) {
			int change = 0;
			dfs(done, city, i, change);
			if (change)
				ans++;
			//forj(r)	cout << done[j] << " ";
			//cout << endl<<"ans="<<ans<<endl;
		}
		cout << ans << endl;
	}
}
