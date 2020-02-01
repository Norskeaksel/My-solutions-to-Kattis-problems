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
#define fin() ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	map<string, string> a;
	a["D#"] = "Eb";
	a["Eb"] = "D#";
	a["A#"] = "Bb";
	a["Bb"] = "A#";
	a["A"] = "UNIQUE";
	a["B"] = "UNIQUE";
	a["C"] = "UNIQUE";
	a["D"] = "UNIQUE";
	a["G"] = "UNIQUE";
	a["E"] = "UNIQUE";
	a["F"] = "UNIQUE";
	a["C#"] = "Db";
	a["Db"] = "C#";
	a["D#"] = "Eb";
	a["Eb"] = "D#";
	a["F#"] = "Gb";
	a["Gb"] = "F#";
	a["G#"] = "Ab";
	a["Ab"] = "G#";

	string note, dur;
	int i = 1;
	while(cin >> note >> dur){
		if (a[note] == "UNIQUE")
			cout << "Case " << i << ": UNIQUE\n";
		else
			cout << "Case "<<i<<": "<<a[note] << " " << dur << endl;
		i++;
	};
}