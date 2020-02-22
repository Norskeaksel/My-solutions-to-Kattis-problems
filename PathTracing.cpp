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

string grid[1234][1234];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	fori(1234) {
		forj(1234) {
			grid[i][j] = " ";
		}
	}
	int x = 555, y = 555;
	int ll = 555, lr = 555, ld = 555, lu = 555;

	grid[x][y] = "S";
	string a;
	while (cin >> a) {
		if (a == "down") {
			y++;
			ld= max(ld, y);
		}
		if (a == "left") {
			x--;
			ll = min(ll, x);
		}
		if (a == "up") {
			y--;
			lu = min(lu, y);
		}
		if (a == "right") {
			x++;
			lr = max(lr, x);
		}
		if (grid[x][y] != "S")
			grid[x][y] = "*";
		//cout << "x = " << x << " y= " << y << endl;
	}
	grid[x][y] = "E";
	ll--; lr++; ld++; lu--;
		for (int j = lu; j <= ld; j++) {
			for (int i = ll; i <= lr; i++) {
			if (i == ll || i == lr || j == lu || j == ld)
				cout << '#';
			else
				cout << grid[i][j];
		}
		cout << endl;
	}
}