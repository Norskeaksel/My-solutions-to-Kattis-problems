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

vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	while (cin >> n) {
		bool none = 1;
		if (!n)
			break;
		int lb = 0, ub = 1e5;
		vll div;
		string a, b;
		int c;
		fori(n) {
			cin >> a >> b >> c;
			if (a == "less")
				ub = min(ub, c);
			if (a == "greater")
				lb = max(lb, c);
			if (a == "divisible")
				div.pb(c);
		}
		
		if (ub == 1e5) {
			cout << "infinite";
			none = 0;
		}
		else {
			for (int j = lb+1; j < ub; j++) {
				trav(div) {
					if (j%i != 0) {
						goto skip;
					}
				}
				none = 0;
				cout << j << " ";
			skip:;
			}
		}
		if (none)
			cout << "none\n";
		else cout << endl;
	}
}