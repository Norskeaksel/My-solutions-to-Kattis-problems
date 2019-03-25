#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;
struct Edge {
	int til;
	int lengde;
	int fra;//unødvendig
};
struct Vertex {
	vector<Edge>kanter;
	int avstand = 1e9;
	bool ubrukt=1;
};
bool operator<(Edge e1, Edge e2) {
	if (e1.lengde > e2.lengde) {
		return true;
	}
	return false;
}

Edge edges[33333];
Vertex nodes[22222];
int main() {
	int nrOfn, nrOfe;
	while (cin >> nrOfn >> nrOfe) {
		long long u, v, w;
		for (int i = 0; i < nrOfe; i++) {
			cin >> u >> v >> w;
			edges[u].til = v;
			edges[u].fra = u;
			edges[u].lengde = w;
			nodes[u].kanter.push_back(edges[u]);
		}
		vector<Edge> all;
		priority_queue<Edge>pq;
		Edge virtual_start_edge = { 0,0 };
		pq.push(virtual_start_edge);
		int svar = 0;
		while (!pq.empty()) {
			Edge currentEdge= pq.top();
			all.push_back(currentEdge);
			pq.pop();
			Vertex currentNode = nodes[currentEdge.til];
			if (currentNode.ubrukt) {
				all.push_back(currentEdge);
				svar += currentEdge.lengde;
				for (auto newEdges : nodes[currentEdge.til].kanter) {
					pq.push(newEdges);
				}
				currentNode.ubrukt = false;
			}
		}
		if (all.size() < nrOfn - 1) {
			cout << "Impossible\n";
		}
		else {
			cout << svar << endl;
			sort(all.begin(), all.end());
			for (int i = 1; i < all.size(); i++) {
				cout << all[i].fra << " " << all[i].til << endl;
			}
		}
	}
}