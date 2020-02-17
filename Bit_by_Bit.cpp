#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
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
	int n;
	while(cin>>n){
		cin.ignore();
		string a = "????????????????????????????????";
		if (!n)
			break;
		fori(n) {
			string b;
			getline(cin, b);
			vector<string> c = strsplit(b);
			if (c[0] == "SET") {
				a[stoi(c[1])] = '1';
			}
			else if (c[0] == "CLEAR") {
				a[stoi(c[1])] = '0';
			}
			else if (c[0] == "AND") {
				int d = stoi(c[1]);
				int e = stoi(c[2]);
				if (a[d] == '1'&&a[e] == '1') {
					a[d] = '1';
				}
				else if (a[d] == '0' || a[e] == '0') {
					a[d] = '0';
				}
				else {
					a[d] = '?';
				}
			}
			else if (c[0] == "OR") {
				int d = stoi(c[1]);
				int e = stoi(c[2]);
				if (a[d] == '1' || a[e] == '1') {
					a[d] = '1';
				}
				else if (a[d] == '0' && a[e] == '0') {
					a[d] = '0';
				}
				else {
					a[d] = '?';
				}
			}
		}
		reverse(all(a));
		cout << a<<endl;
	}
}