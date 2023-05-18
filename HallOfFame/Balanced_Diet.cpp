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

ll knapsack(vll weight, vll value, ll cappacity){
	ll n = weight.size();
	vector<vll> T(22, vll(cappacity+1, 0));//table of value given cappacity
	for (ll i = 1; i <= n;i++) {
		for (ll w = 0; w <= cappacity;w++) {
			if(weight[i-1]<= w){
				T[i][w] = max(T[i - 1][w], value[i-1] + T[i - 1][w - weight[i-1]]);
			}
			else{
				T[i][w] = T[i - 1][w];
			}
		}
	}
	return T[n][cappacity];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	while (1){
		ll cap;
		ll n;
		cin >> n;
		if(!n)
			break;
		vll a(n);
		ll target=0;
		trav(a) {
			cin >> i;
			target += i;
		}
		ll p1 = knapsack(a, a, target / 2);
		ll p2 = target - p1;
		cout << p2 << " " << p1 << endl;
	}
}