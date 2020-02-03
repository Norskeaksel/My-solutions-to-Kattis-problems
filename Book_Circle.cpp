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

const int nax =12345;
vector<int> node[nax];
int done[nax];

struct Edge {
	int start, end;
	ll flow, cap;
};
vector<Edge> edges;
ll maxflow(int p, int sink, ll ma = 1e18) {
	if (p == sink) return ma;
	done[p] = 1;
	for (int ei : node[p]) {
		Edge&e = edges[ei];
		ll flow;
		if (e.flow < e.cap && !done[e.end] && (flow = maxflow(e.end, sink, min(ma, e.cap - e.flow)))) {
			edges[ei].flow += flow;
			edges[ei ^ 1].flow -= flow;
			return flow;
		}
	}
	return 0;
}

void addEdge(int a, int b, ll c) {
	node[a].push_back(edges.size());
	edges.push_back({ a,b,0,c });
	node[b].push_back(edges.size());
	edges.push_back({ b,a,0,0 });
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int b, g;
	cin >> b >> g;
	map<string, int>book2dude;
	forx(b) {
		string dude;
		int a;
		cin >> dude >> a;
		forj(a) {
			string book;
			cin >> book;
			book2dude[book] = x;
		}
		addEdge(0, x, 1);
	}
	forx(g){
		string dude;
		int a;
		cin >> dude >> a;
		forj(a) {
			string book;
			cin >> book;
				if (book2dude[book]) {
					addEdge(book2dude[book], b + x, 1);
				}
		}
		addEdge(x+b, b+g+1, 1);
	}
	ll tot = 0;
	ll source = 0;
	ll sink = b + g + 1;
	while (1) {
		fill_n(done, nax, 0);
		ll flow = maxflow(source, sink);
		if (!flow) break;
		tot += flow;
	}
	cout << tot;
}