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

/*Input format
3 4
1 2 3
2 3 1
1 3 7
2 1 5
*/

ll dist[1234567]; 
vector<pair<ll, ll>>node[1234567];
void dijkstra(ll start) {
	fill_n(dist, 1234567, 1e18);
	dist[start] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pair<ll, ll> u = { 0,start };
	pq.push(u);
	while (!pq.empty()) {
		u = pq.top();//dist to this node and this node nr
		pq.pop();
		ll d = u.first;//dist to this node
		ll nr = u.second;//this node nr
		if (dist[u.second] < u.first)continue;//dersom det er en lettere vei å komme seg til neste node enn å gå via nåværende node så skal vi ikke prossessere den nåverende noden
		for (auto e : node[u.second]) {
			if (dist[e.second] > dist[nr] + e.first) {
				dist[e.second] = dist[nr] + e.first;
				pq.push({ dist[e.second],e.second });
			}
		}
	}
}

const ll shadow = 1e5;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n, m;
	cin >> n>> m;
	fori(m){
		ll a, b, c;
		cin >> a >> b >> c;
		node[a].pb(make_pair(c,b));
		node[a].pb(make_pair(c / 2,b + shadow ));
		node[a + shadow].pb(make_pair(c, b + shadow));
	}
	dijkstra(1);
	cout << dist[n+shadow]<<endl;
}