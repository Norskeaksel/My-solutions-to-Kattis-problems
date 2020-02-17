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
	int a, b;
	while (1) {
		cin >> a;
		if (a == 0)
			break;
		vll key(a);
		trav(key)
			cin >> i;
		string str,str2;
		cin.ignore();
		getline(cin, str);
		int sz = str.size();
		int ks = key.size();
		while((sz++)%ks){
			str += ' ';
		}
		str2 = str;
		for (int i = 0; i < str.size(); i += ks) {
			for (int j = i; j < i + ks; j++) {
				int nr = key[j - i] - 1;
				char d = str[nr+i];
				str2[j]=d;
				//cout << str2 << endl;
			}
		}
		cout << "'";
		fori(str.size())
			cout << str2[i];
		cout << "'\n";
	}
}