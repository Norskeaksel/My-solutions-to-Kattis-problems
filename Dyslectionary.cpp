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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	vector<string>s[123];
	string str;
	int c = 0;
	while (getline(cin, str)) {
		if (str.empty())
			c++;
		reverse(all(str));
		s[c].pb(str);
	}
	forj(c + 1) {
		int maxL = 0;
		trav(s[j]) {
			int b = i.size();
			maxL = max(maxL, b);
		}
		sort(all(s[j]));
		trav(s[j]) {
			reverse(all(i));
			if (!i.empty())
				cout << right << setw(maxL) << i << endl;
			else
				cout << endl;
		}
	}
}