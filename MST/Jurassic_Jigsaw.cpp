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
	int start;
	int end;
	int weight;
};
struct Vertex {
	int parent;
	int done = 0;
	vector<Edge>neighbors;
};

bool operator <(Edge a, Edge b) {
	return a.weight > b.weight;
}

ll diffrence(string a,string b){
	ll c = 0;
	fori(a.size()){
		c += a[i] != b[i];
	}
	return c;
}

void MST(vector<Vertex>DNA) {
	priority_queue<Edge> pq;
	vpl chosen;
	pq.push({ 0,0 });
	ll dist = 0;
	unsigned int included = 0;
	while (included < DNA.size()) {
		Edge u = pq.top();
		pq.pop();
		if (DNA[u.end].done)continue;
		if (included) {
			chosen.pb(make_pair(u.start, u.end));
		}
		included++;
		dist += u.weight;
		DNA[u.end].done = 1;
		for (auto e : DNA[u.end].neighbors) {
			if (!DNA[e.end].done) {
				pq.push(e);
			}
		}
	}
	cout << dist << endl;
	trav(chosen){
		cout << i.first << " " << i.second<<endl;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n, k;
	cin >> n >> k;
	vector<string> str(n);
	trav(str)
		cin >> i;
	vector<Vertex>DNA(n);
	fori(n){
		forj(n){
			ll diff = diffrence(str[i], str[j]);
			Edge neighbour{ i,j,diff };
			DNA[i].neighbors.pb(neighbour);
		}
	}
	MST(DNA);
}