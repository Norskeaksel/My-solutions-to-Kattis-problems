#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Edge {
	int til;
	int lengde;
	int fra;
};
struct Vertex{
	vector<Edge>kanter;
	int avstand= 1e9;
};
bool operator<(Edge e1, Edge e2) {
	if (e2.lengde < e1.lengde)
		return true;
	return false;
}
Edge edges[33333];
Vertex nodes[22222];
int main() {
	int n, e, q, start;
	while (cin >> n >> e >> q >> start) {
		if (!(n || e || q || start))
			break;
		Edge d;
		fill_n(edges, 33333, d);
		Vertex b;
		fill_n(nodes, 12345, b);
		int u, v, w;
		for (int y = 0; y < e; y++) {
			cin >> u >> v >> w;
			edges[u].til = v;
			edges[u].fra = u;
			edges[u].lengde = w;
			nodes[u].kanter.push_back(edges[u]);
		}

		nodes[start].avstand = 0;
			priority_queue<Edge>pq;
			Edge virtual_start_edge = { start,0 };
			pq.push(virtual_start_edge);
			while (!pq.empty()) {
				Edge current = pq.top();
				pq.pop();
				for (auto newEdge : nodes[current.til].kanter) {
					int& originalNodeDist = nodes[newEdge.til].avstand;
					int newNodedist = nodes[current.til].avstand+newEdge.lengde;
					if (originalNodeDist > newNodedist ) {
						originalNodeDist = newNodedist;
						Edge ny = { newEdge.til,originalNodeDist };
						pq.push(ny);
					}
				}
			}
			/*for (int i = 0; i < n; i++) {
				cout << nodes[i].avstand << " ";
			}*/
				int goal;
				for (int i = 0; i < q; i++) {
					cin >> goal;
					if (nodes[goal].avstand < 1e9)
						cout << nodes[goal].avstand << endl;
					else
						cout << "Impossib	le\n";
				}
				cout << endl;
	}
}