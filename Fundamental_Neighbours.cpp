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

int isPrime(int n) {
	if (n == 2 || n == 3)
		return 1;
	if (n < 2 || n % 2 == 0 || n % 3 == 0)
		return 0;
	for (int i = 5; i <= int(sqrt(n)) + 1; i += 6)
		if (n%i == 0 || n % (i + 2) == 0)
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n;
	while (cin >> n) {
		ll org = n;
		map<ll, ll> factor;
		for (ll i = 2; i <= ll(sqrt(n)); i++) {
			if (isPrime(i)) {
				while (n%i == 0) {
					n /= i;
					factor[i]++;
				}
			}
		}
		if (n != 1) {
			factor[n]++;
		}
		ll ans = 1;
		for (auto i : factor) {
			ans *= pow(i.second, i.first);
		}
		cout << org<<" "<<ans << endl;
	}
}