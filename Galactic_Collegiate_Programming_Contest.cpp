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
int graph[2345][2345];
int main() {
	int t;
	cin >> t;
	while (t--) {
		fill_n((int*)graph, 2345 * 2345, 0);
		int parent[2345], key[2345];
		int mstSet[2345] = {};
		fill_n(key, 2345, 1e9);
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
		cout << svar << endl;
		if (svar > m)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}