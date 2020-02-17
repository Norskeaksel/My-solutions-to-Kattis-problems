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
	int n;
	while (cin >> n) {
		if (n == 4)
			break;
		int add = 1;
		int c = 0;
		while (add) {
			add = 0;
			c++;
			for (int i = 0; i <= sqrt(n) + 1; i += 6) {
				if (i == n || n == 1 || n == 2 || n == 3) {
					break;
				}
				if(i < 6){
					while (n % 2 == 0) {
						add += 2;
						n /= 2;
					}
					while (n % 3 == 0) {
						add += 3;
						n /= 3;
					}
				}
				else  {
					while (n % (i - 1) == 0) {
						add += (i - 1);
						n /= (i - 1);
					}
					while (n % (i + 1) == 0) {
						add += (i + 1);
						n /= (i + 1);
					}
				}
			}
			if (add) {
				if (n == 1)
					n--;
				if (n == 2)
					n -= 2;
				n += add;
			}
		}
		cout << n << " " << c << endl;
	}
}
	/*	if (n % 2 == 0) {
	n /= 2;
	add += 2;
	i = 0;
}
else if (n % 3 == 0) {
	n /= 3;
	add += 3;
	i -= 6;
}
}
else {
	if (n % (i - 1) == 0) {
		n /= (i - 1);
		add += (i - 1);
		i -= 6;
	}
	else if (n % (i + 1) == 0) {
		n /= (i + 1);
		add += (i + 1);
		i -= 6;
	}
}
}
if(add)
	n = add;*/