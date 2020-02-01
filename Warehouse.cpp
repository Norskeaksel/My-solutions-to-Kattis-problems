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
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in(t) ll t; cin >> t; while(t--)
#define fin(n) ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)

template <class T>
void ipb(vector<T>&v) {
	T a;
	cin >> a;
	v.pb(a);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in(t) {
		map<string, int> ware;
		fin(n) {
			string a;
			int b;
			cin >> a >> b;
			ware[a] += b;
		}
		vector<pair<int,string >>ans;
		trav(ware) {
			pair<int, string>p = { -i.dy,i.dx };
			ans.pb(p);
		}
		sort(all(ans));
		int s = sz(ans);
		fory(s - 1) {
			forx(s - 1) {
				string prev = ans[x - 1].dy;
				string next = ans[x].dy;
				int l = sz(next);
				string sub = next.substr(0, l);
				if (ans[x - 1].dx == ans[x].dx && sz(prev) > l&&prev.substr(0, l) == sub)
					swap(ans[x], ans[x - 1]);
			}
		}
		cout <<s << endl;
		trav(ans) {
			cout << i.dy << " " << -i.dx << endl;
		}
	}
}