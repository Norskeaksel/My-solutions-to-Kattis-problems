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

struct edge {
	int start;
	int end;
	int weight;
};
struct vertex {
	int parent;
	int done=0;
	vector<edge>neighbors;
};
	
bool operator <(edge a, edge b) {
	if (a.weight > b.weight)
		return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m, c;
		cin >> m >> c;
		vector<vertex>node(c);
		fori(c*(c - 1) / 2) {
			int start, end, weight;
			cin >> start >> end >> weight;
			node[start].neighbors.push_back({ start,end,weight });
			node[end].neighbors.push_back({ end,start,weight });
		}
		priority_queue<edge>pq;
		pq.push({ -1,0,0 });
		int svar = c;
		while (!pq.empty()){
			edge best = pq.top();
			pq.pop();
			if (node[best.end].done++)
				continue;
			svar += best.weight;
			for (edge e : node[best.end].neighbors) {
				if(!node[e.end].done)
					pq.push(e);
			}
		}
		//cout << svar << endl;
		if (svar > m)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}