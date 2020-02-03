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

template <class T>
void vb(vector<T>&v) {
	T a;
	cin >> a;
	v.pb(a);
}
ll matrix[1234][1234];
void floyd_warshall(ll n) {//matrisedimensjon
	fork(n) {
		fori(n) {
			forj(n) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
}
ll ans;
vll neighbour[1234];
void newPath(ll cur, ll n) {
	trav(neighbour[cur]) {
		ll a = matrix[i][2];
		ll b= matrix[cur][2];
		if (a < b) {
			ans++;
			newPath(i, n);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n, m;
	while(cin>>n>>m){
		ans = 0;
		fill_n((ll*)matrix, 1234 * 1234, 1e3);
		fori(m){
			ll a, b, c;
			cin >> a >> b >> c;
			neighbour[a].pb(b);
			neighbour[b].pb(a);
			matrix[a][b] = c;
			matrix[b][a] = c;
		}
		floyd_warshall(n);
		fory(n) {
			forx(n) {
				cout << matrix[x][y] << "\t";
			}
			cout << endl;
		}
		newPath(1, n);
		cout<<ans << endl;
	}
}
