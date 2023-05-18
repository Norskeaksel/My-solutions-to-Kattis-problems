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

#define x first
#define y second
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

pll goal(ll h, ll w, ll dist[61][61]) {
	ll min = 1e9;
	pll xy = { 0,h };
	forx(w) {
		if (dist[x][h] < min) {
			min = dist[x][h];
			xy.x = x;
		}
	}
	return xy;
}

void backtrack(ll h, ll w, ll matrix[61][61], ll dist[61][61], pll parent[61][61]) {
	pll a = goal(h, w, dist);
	//cout << dist[a.x][a.y] << endl;
	while (a.y != 0) {
		matrix[a.x][a.y] = -1;
		a = parent[a.x][a.y];
	}
	fory(h) {
		forx(w) {
			if (matrix[x][y] == -1)
				cout << " ";
			else
				cout << matrix[x][y];
		}
		cout << endl;
	}
	cout << endl;
}

void dijkstra(ll h, ll w, ll matrix[61][61], ll dist[61][61], pll parent[61][61]) {
	fill_n((ll*)dist, 61 * 61, 1e9);
	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
	for (ll starts = 1; starts <= w; starts++) {
		dist[starts][0] = 0;
		pq.push({ 0, {starts,0} });
	}
	while (!pq.empty()) {
		pair<ll, pll> node = pq.top();//dist to this node and its coordinates
		pq.pop();
		ll x = node.second.x;
		ll y = node.second.y;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				ll dx = x + i;
				ll dy = y + j;
				if (dx<1 || dx>w || dy > h || dy < 0)
					continue;
				if (dist[dx][dy] > dist[x][y] + matrix[dx][dy]) {
					dist[dx][dy] = dist[x][y] + matrix[dx][dy];
					pq.push({ dist[dx][dy],{ dx, dy} });
					parent[dx][dy] = { x,y };
				}
			}
		}
	}
	backtrack(h, w, matrix, dist, parent);
}
int main() {
	ll h, w;
	while (cin >> h >> w) {
		ll matrix[61][61];
		ll dist[61][61];
		pll parent[61][61];
		if (h == 0 && w == 0)
			break;
		fory(h) {
			forx(w) {
				char a;
				cin >> a;
				matrix[x][y] = a - '0';
			}
		}
		dijkstra(h, w, matrix, dist, parent);
	}
}