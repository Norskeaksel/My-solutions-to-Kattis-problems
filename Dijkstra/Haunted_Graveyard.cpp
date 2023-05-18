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

struct Edge {
	ll x2, y2;
	ll weight;
};

struct Vertex {
	bool seen = 0;
	bool isGrave = 0;
	bool isPortal = 0;
	vector<Edge>neighbour;
};

bool operator <(Edge a, Edge b) {
	return a.weight > b.weight;
}

void print(ll arr[30][30],ll gx,ll gy) {
	for (ll y = 0; y < gy; y++) {
		for (ll x = 0; x < gx; x++) {
			cout << x << " " << y << " " << arr[x][y] << endl;
		}
	}
}
void BellmanFord(Vertex node[30][30], pll goal) {
	ll dist[30][30];
	ll gx = goal.dx, gy = goal.dy;
	fori(gx) {
		forj(gy) {
			dist[i][j] = 1e9;
		}
	}
	dist[0][0] = 0;
	fork(gx*gy) {
		for (ll y = 0; y < gy; y++) {
			for (ll x = 0; x < gx; x++) {
				trav(node[x][y].neighbour) {
					ll oldDist = dist[i.x2][i.y2];
					ll newDist = dist[x][y] + i.weight;
					if (newDist < oldDist&&newDist < 5e8) {
						dist[i.x2][i.y2] = newDist;
					}
				}
				//cout << x << " " << y << " " << dist[x][y] << endl;
			}
		}
	}
	//print(dist,gx,gy);
	fork(gx * gy) {
		for (ll y = 0; y < gy; y++) {
			for (ll x = 0; x < gx; x++) {
				trav(node[x][y].neighbour) {
					ll oldDist = dist[i.x2][i.y2];
					ll newDist = dist[x][y] + i.weight;
					if (newDist < oldDist&&newDist < 5e8)
						dist[i.x2][i.x2] = -1e9;
				}
			}
		}
	}
	ll fin = dist[goal.dx - 1][goal.dy - 1];
	if (fin == -1e9)
		cout << "Never\n";
	else if (fin > 1e6) {
		cout << "Impossible\n";
	}
	else
		cout << fin << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	while (1) {
		Vertex node[30][30];
		ll w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		ll g;
		cin >> g;
		fori(g) {
			ll x, y;
			cin >> x >> y;
			node[x][y] = { 1,1,0 };
		}
		ll e;
		cin >> e;
		fori(e) {
			ll x1, y1, x2, y2, T;
			cin >> x1 >> y1 >> x2 >> y2 >> T;
			node[x1][y1] = { 1,0,1 };
			node[x1][y1].neighbour.push_back({ x2,y2,T });
		}
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {
				for (int i = 0; i < 4; i++) {
					int nx = x + (i == 0) - (i == 1);
					int ny = y + (i == 2) - (i == 3);
					if (nx >= 0 && nx < w&&ny >= 0 && ny < h) {
						if (node[nx][ny].isGrave)
							node[x][y].neighbour.push_back({ nx,ny,int(1e9) });
						else
							node[x][y].neighbour.push_back({ nx,ny,1 });
					}
				}
			}
		}
		BellmanFord(node, { w,h });
	}
}