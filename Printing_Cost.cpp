#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h>
using namespace std;
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

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
	map<char, int> a;
	a[' '] = 0;
	a['!'] = 9;
	a['"'] = 6;
	a['#'] = 24;
	a['$'] = 29;
	a['%'] = 22;
	a['&'] = 24;
	a['\''] = 3;
	a['('] = 12;
	a[')'] = 12;
	a['*'] = 17;
	a['+'] = 13;
	a[','] = 7;
	a['-'] = 7;
	a['.'] = 4;
	a['/'] = 10;
	a['0'] = 22;
	a['1'] = 19;
	a['2'] = 22;
	a['3'] = 23;
	a['4'] = 21;
	a['5'] = 27;
	a['6'] = 26;
	a['7'] = 16;
	a['8'] = 23;
	a['9'] = 26;
	a[':'] = 8;
	a[';'] = 11;
	a['<'] = 10;
	a['='] = 14;
	a['>'] = 10;
	a['?'] = 15;
	a['@'] = 32;
	a['A'] = 24;
	a['B'] = 29;
	a['C'] = 20;
	a['D'] = 26;
	a['E'] = 26;
	a['F'] = 20;
	a['G'] = 25;
	a['H'] = 25;
	a['I'] = 18;
	a['J'] = 18;
	a['K'] = 21;
	a['L'] = 16;
	a['M'] = 28;
	a['N'] = 25;
	a['O'] = 26;
	a['P'] = 23;
	a['Q'] = 31;
	a['R'] = 28;
	a['S'] = 25;
	a['T'] = 16;
	a['U'] = 23;
	a['V'] = 19;
	a['W'] = 26;
	a['X'] = 18;
	a['Y'] = 14;
	a['Z'] = 22;
	a['['] = 18;
	a['\\'] = 10;
	a[']'] = 18;
	a['^'] = 7;
	a['_'] = 8;
	a['`'] = 3;
	a['a'] = 23;
	a['b'] = 25;
	a['c'] = 17;
	a['d'] = 25;
	a['e'] = 23;
	a['f'] = 18;
	a['g'] = 30;
	a['h'] = 21;
	a['i'] = 15;
	a['j'] = 20;
	a['k'] = 21;
	a['l'] = 16;
	a['m'] = 22;
	a['n'] = 18;
	a['o'] = 20;
	a['p'] = 25;
	a['q'] = 25;
	a['r'] = 13;
	a['s'] = 21;
	a['t'] = 17;
	a['u'] = 17;
	a['v'] = 13;
	a['w'] = 19;
	a['x'] = 13;
	a['y'] = 24;
	a['z'] = 19;
	a['{'] = 18;
	a['|'] = 12;
	a['}'] = 18;
	a['~'] = 9;
	string s;
	while (getline(cin, s)){
		int ans = 0;
		trav(s){
			ans += a[i];
		}
		cout << ans << endl;
	}
}