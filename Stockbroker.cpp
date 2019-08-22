#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 
#include <immintrin.h>

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
	ll cash = 100;
	ll stocks = 0;
	vll price;
	in(t) {
		ipb(price);
	}
	fori(price.size() - 1) {
		cash += stocks * price[i];
		stocks = 0;
		if (price[i + 1] > price[i]) {
			stocks = min(cash / price[i], 100000LL);
			cash -= stocks * price[i];
		}
	}
	cash += stocks * price[price.size() - 1];
	cout << cash << endl;
}