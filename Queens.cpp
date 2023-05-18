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

int dx = 5000;
int board[15000][15000];
void check(int queens){
	if (queens != 1) {
		cout << "INCORRECT\n";
		exit(0);
	}
}
void check2(int queens) {
	if (queens > 1) {
		cout << "INCORRECT\n";
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	cin >> n;
	fori(n){
		int x, y;
		cin >> x >> y;
		board[x+dx][y+dx] = 1;
	}
	//cout << board[5000][5003];
	for(int x=0;x<n;x++){ //vertical
		int queens = 0;
		for(int y=0;y<n;y++){
			if (board[x+dx][y+dx])
				queens++;
		}
		check(queens);
	}
	for (int y = 0; y < n; y++) { //horrisontal
		int queens = 0;
		for (int x = 0; x < n; x++) {
			if (board[x+dx][y+dx])
				queens++;
		}
		check(queens);
	}
	for(int x=0;x<10000;x++){ //upright
		int queens = 0;
		int y = 0;
		for(int xx=x;xx<10000;xx++){
			if (board[xx][y++]){
				queens++;
			}
		}
		check2(queens);
	}
	for (int x = 0; x < 10000; x++) { //downright
		int queens = 0;
		int y = 10000;
		for (int xx = x; xx < 10000; xx++) {
			if (board[xx][y--]) {
				queens++;
			}
		}
		check2(queens);
	}
	cout << "CORRECT\n";
}