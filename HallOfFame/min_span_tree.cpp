//#include<bits/stdc++.h> includerer alt, men fungerer ikke i c++
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <iomanip>
#include <iterator>
#include <queue>
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define ll long long
#define double long double

struct edge {
	int start;
	int end;
	int weight;
};

struct vertex {
	int parent;
	int done = 0;
	vector<edge>neighbors;
};

bool operator <(edge a, edge b) {
	if (a.weight > b.weight)
		return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		vector<vertex>node(n);
		if (!(n || m))
			exit(0);
		fori(m) {
			int u, v, w;
			cin >> u >> v >> w;
			node[u].neighbors.push_back({ u,v,w });
			node[v].neighbors.push_back({ v,u,w });
		}
		priority_queue<edge> pq;
		pq.push({ -1,0,0 });
		ll tot = 0;
		int edgenr = -1;
		vector<pair<int, int>>svar;
		while (!pq.empty()) {
			//cout << "entered\n";
			edge best = pq.top();
			pq.pop();
			if (node[best.end].done++) {
				continue;
			}
			edgenr++;
			tot += best.weight;
			svar.push_back({ best.start,best.end });
			for (edge e : node[best.end].neighbors) {
				//if(!node[e.end].done++)
				pq.push(e);
			}
		}
		fori(svar.size()) {
			if (svar[i].second < svar[i].first)
				swap(svar[i].second, svar[i].first);
		}
		sort(svar.begin(), svar.end());
		if (edgenr < n-1)
			cout << "Impossible\n";
		else {
			cout << tot << endl;
			forx(svar.size()-1){
				cout << svar[x].first << " " << svar[x].second << endl;
			}
		}
	}
}