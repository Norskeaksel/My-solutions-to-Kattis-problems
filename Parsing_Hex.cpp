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

ll hexadecimalToDecimal(char num[]) {
	ll len = strlen(num);
	for (ll i = len - 1; i >= 0; i--){
		num[i] = toupper(num[i]);
	}
	ll base = 1;
	ll temp = 0;
	for (ll i = len - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			temp += (num[i] - 48)*base;
			base = base * 16;
		}
		else if (num[i] >= 'A' && num[i] <= 'F') {
			temp += (num[i] - 55)*base;
			base = base * 16;
		}
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	set<char> a;
	string s = "0123456789abcdefABCDEF";
	trav(s)
		a.insert(i);
	while (cin >> s) {
		s += "+++";
		fori(s.size() - 2) {
			int c = 0;
			if (s[i] == '0'&&(s[i + 1] == 'x'|| s[i + 1] == 'X')) {
				int j = i+2;
				while (a.count(s[j])){
					j++;
					c++;
				}
				char* hexVal =new char[c];
				j = i + 2;
				c = 0;
				cout << "0x";
				while (a.count(s[j])) {
					cout << s[j];
					hexVal[c] = s[j];
					c++;
					j++;
				}

				cout <<" "<< hexadecimalToDecimal(hexVal)<<endl;
			}
		}
	}
}