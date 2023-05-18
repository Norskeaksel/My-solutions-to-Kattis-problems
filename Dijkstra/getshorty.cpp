#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define fori(n) for (int i=0;i<n;i++)

void dijkstra(vector<pair<double, int>>node[23456], double weight[23456],int goal, int start = 0) {
	fill_n(weight, 23456, -1e9);
	weight[start] = 1;
	pair<double, int>edge = { 1,start };//weight to start node is 1
	priority_queue<pair<double, int>>pq;
	pq.push(edge);
	while (!pq.empty()) {
		edge = pq.top();
		pq.pop();
		//if (weight[edge.second] > edge.first)continue;//if weight of neighbor node is greater, than weight to that node, skip this node
		for (auto e : node[edge.second]) {//for all edges of the node
			if (weight[e.second] < weight[edge.second] *  e.first) {
				weight[e.second] = weight[edge.second] * e.first;
				pq.push({ weight[e.second], e.second });
			}
		}
	}
}

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)
			exit(0);
		vector<pair<double, int>>node[23456];//array with the neighbors of the node 
		double weight[23456];
		fori(m) {
			int x, y;
			double f;
			cin >> x >> y >> f;
			node[x].push_back({ f,y });
			node[y].push_back({ f,x });
		}
		dijkstra(node,weight,n - 1);
		cout << fixed << setprecision(4)<< weight[n - 1] << endl;
	}
}