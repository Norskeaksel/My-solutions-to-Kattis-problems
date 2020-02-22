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

vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	
	while (1) {
		int n;
		cin >> n;
		if (!n)
			break;
		vpd ans;
		ld avx = 0, avy = 0;
		fork(n) {
			ld x=0, y=0, o=0, r=0;
			string str;
			cin.ignore();
			getline(cin, str);
			vs b = strsplit(str);
			for (int i = 0; i < b.size(); i++) {
				if (i == 0)
					x = stod(b[i]);
				else if (i == 1)
					y = stod(b[i]);
				else if (i == 3)
					o = stod(b[i]);
				else {
					if (b[i] == "walk") {
						x += cos(o*acos(-1)/180.0)*stod(b[i + 1]);	
						y += sin(o*acos(-1) / 180.0)*stod(b[i + 1]);
					}
					if (b[i] == "turn")
						o += stod(b[i + 1]);
				}
			}
			cout << k<<" x= " << x << " y= " << y << endl;
			ans.pb(make_pair(x, y));
		}
		
		trav(ans){
			avx += i.first;
			avy += i.second;
		}
		avx /= ld(ans.size());
		avy/= ld(ans.size());
		cout << avx << " " << avy << endl;
	}
}