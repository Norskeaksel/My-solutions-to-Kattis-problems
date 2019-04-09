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
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define ll long long
#define double long double

int minKey(int key[], int mstSet[], int c) {
	int minValue = 1e9, minIndex;
	fori(c)
		if (mstSet[i] == 0 && key[i] < minValue)
			minValue = key[i], minIndex = i;

	return minIndex;
}
int printMST(int parent[], int n, int graph[20002][20002]){
	vector<pair<int, int>>s;
	pair<int, int>dummy;
	dummy.first = -1;
	dummy.second = -1;
	s.push_back(dummy);
	ll weight = 0;
	for (int i = 1; i < n; i++) {
		dummy.first = parent[i];
		dummy.second = i;
		s.push_back(dummy);
		weight += graph[i][parent[i]];
	}
	sort(s.begin(), s.end());
	for (int i = 1; i < n; i++){
		cout << s[i].first << " " << s[i].second<<endl;
	}
	cout << weight << endl;
}
int graph[20002][20002];
int main(){
	int nodes, edges;
	while (1) {
		cin >> nodes >> edges;
		if (nodes == 0 && edges == 0)
			exit(0);
		fill_n((int*)graph, 20002 * 20002, 0);
		int parent[20002], key[20002];
		int mstSet[20002] = {};
		fill_n(key, 20002, 1e9);
		ll m, c;
		cin >> m >> c;
		fori(c*(c - 1) / 2) {
			int start, end, weight;
			cin >> start >> end >> weight;
			graph[start][end] = weight;
			graph[end][start] = weight;
		}
		/*fori(c) {
			forj(c) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}*/
		key[0] = 0;
		parent[0] = -1;
		fori(c - 1) {
			int u = minKey(key, mstSet, c);
			mstSet[u] = 1;
			for (int v = 0; v < 2345; v++) {
				if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
					parent[v] = u;
					key[v] = graph[u][v];
				}
			}
		}
		ll svar = c;
		forx(c - 1) {
			//cout << "x=" << x << " " << "parent[x]=" << parent[x] << " graph=" << graph[x][parent[x]]<<endl;
			svar += graph[x][parent[x]];
		}
		if (svar > m)
			cout << "Impossible";
		else {
			printMST(parent,  n, graph)
		}
	}
}