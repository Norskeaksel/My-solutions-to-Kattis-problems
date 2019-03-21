#include<iostream>
#include<utility>
#include <queue>
#include <algorithm>
#include<vector>
using namespace std;
int grid[1234][1234];
pair<int, int> nodes[1234];
int main() {
	fill_n(nodes, 1234, make_pair( -11111 ,0));
	int n, start, slutt,avstand;
	cin >> n >> start >> slutt;
	for (int y = 0; y < n; y++) {
		nodes[y].second = y;
		for (int x = 0; x < n; x++) {
			cin >> avstand;
			grid[x][y] = avstand*-1;
		}
	}
	priority_queue<pair<int,int>>pq;//avstand og nummer
	pair<int, int>u;
	u.first = 0;
	u.second = start;
	nodes[u.second].first = 0;
	pq.push(u);
	//for (int i = 0; i < n; i++) cout << nodes[i].first << " ";
	while (!pq.empty()) {
		u = pq.top();
		pq.pop();
		for (int i = 0; i < n; i++) {
			if(nodes[i].first< nodes[u.second].first+grid[i][u.second]){
				nodes[i].first = nodes[u.second].first + grid[i][u.second];
				pq.push(nodes[i]);
			}
		}
	}
	//for (int i = 0; i < n; i++) cout << nodes[i].first*-1 << " ";
	cout << nodes[slutt].first*-1 << endl;
}