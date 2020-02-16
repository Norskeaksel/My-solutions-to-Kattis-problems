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
	string a;
	map<string, int> b;
	while(getline(cin,a)){
		vector<string>c=strsplit(a);
		if(c[0]== "define"){
			b[c[2]] = stoi(c[1]);
		}
		else if(c[0]== "eval"){
			if(b.count(c[1])==0|| b.count(c[3]) == 0){
			cout << "undefined\n";
			}
			else if(c[2] =="<"){
				if (b[c[1]] < b[c[3]]) {
					cout << "true\n";
				}
				else
					cout << "false\n";
			}
			else if(c[2]==">"){
				if (b[c[1]] > b[c[3]]) {
					cout << "true\n";
				}
				else
					cout << "false\n";
			}
			else if (c[2] == "=") {
				if (b[c[1]] == b[c[3]]) {
					cout << "true\n";
				}
				else
					cout << "false\n";
			}
		}
	}
}