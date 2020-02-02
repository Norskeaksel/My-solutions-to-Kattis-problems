#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
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

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in(t) ll t; cin >> t; while(t--)
#define fin(n) ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)

template <class T>
void ipb(vector<T>&v) {
	T a;
	cin >> a;
	v.pb(a);
}
vector<string>permutations;
void findPermutations(string str, int i=0) {
	int n = str.size();
	if (i == n - 1) {
		permutations.push_back(str);
		return;
	}	
	for (int j = i; j < n; j++) {
		swap(str[i], str[j]);// swap character at index i with current character
		findPermutations(str, i + 1);// recurse for string [i+1, n-1]
		swap(str[i], str[j]);// backtrack (restore the string to its original state)
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	findPermutations("asdfghjkl");
	int a, b;
	cin >> a >> b;
	fori(b){
		cout << permutations[i] << " ";
	}
}