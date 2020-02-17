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

vector<string> split(const string& str, string delimiters) {
	vs ans;
	size_t beg, pos = 0;
	while ((beg = str.find_first_not_of(delimiters, pos)) != string::npos) {
		pos = str.find_first_of(delimiters, beg + 1);
		ans.push_back(str.substr(beg, pos - beg));
	}
	return ans;
}
struct Time {
	int hour;
	int min;
	string raw;
	Time(string raw) : raw(raw) {
		vs a = split(raw, ": ");
		hour = stoi(a[0]);
		if (hour == 12)
			hour = 0;
		min = stoi(a[1]);
		if (a[2] == "p.m.")
			hour += 12;
	}
};

bool operator <(Time a, Time b) {
	return tie(a.hour, a.min) < tie(b.hour, b.min);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	while (cin >> n) {
		cin.ignore();
		vector<Time> a;
		fori(n) {
			string raw;
			getline(cin, raw);
			Time c(raw);
			a.pb(c);
		}
		sort(all(a));
		trav(a) {
			cout << i.raw << endl;
		}
		cout << endl;
	}
}