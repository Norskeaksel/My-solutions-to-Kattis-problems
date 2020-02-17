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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	string a, b;
	map<string, pair<ld,ld>> m[23];
	int c;
	int d = 0;
	while(cin>>a){
		if(a=="OPEN")
			continue;
		if(a == "CLOSE"){
			d++;
			cout << "Day " << d << endl;
			trav(m[d-1]){
				cout <<setprecision(2)<<fixed<< i.first << " $" << i.second.second << endl;
			}
			continue;
		}
		cin >> b >> c;
		if(a=="ENTER"){
			m[d][b].first = c;
		}
		if (a == "EXIT") {
			m[d][b].second += (c- m[d][b].first)*0.1;
		}
	}
}