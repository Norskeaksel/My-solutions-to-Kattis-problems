//#include<bits/stdc++.h> includerer alt, men fungerer ikke i visual studio
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>//For å jobbe med filer
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <cstdlib>//rand()
#include <ctime> //srand()
#include <iterator>
#include <queue>
#include <stack>
#include <functional>// tillater bruk av greater<int>
#include <stdio.h>// tillater automatisk lesing av testinnput
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define all(v) (v).begin(),(v).end()
#define ll long long
#define dx first
#define dy second
#pragma warning(disable:4996)
int dist[2000][2000];
char grid[2000][2000];
int dijkstra(pair<int, int> start, int row, int col) {
	fill_n((int*)dist, 4000000, 1e9);
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> >>>pq;
	pq.push({ 1,start });
	dist[start.dx][start.dy] = grid[start.dx][start.dy] == 'c';
	while (!pq.empty()) {
		int x = pq.top().second.dx;
		int y = pq.top().second.dy;
		if (x == col - 1 || y == row - 1 || x == 0 || y == 0)
			return dist[x][y];
		/*cout << grid[x][y] << endl;
		fori(row) {
			forj(col) {
				cout << dist[j][i]<<"\t";
			}
			cout << endl;
		}
		system("pause");*/
		pq.pop();
		grid[x][y] = '#';
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			if (grid[nx][ny] != '#') {
				int avstand = dist[x][y] + (grid[nx][ny] == 'c');
				//cout << "nx=" << nx << " " << "ny=" << ny <<" "<< grid[nx][ny]<< endl;
				//system("pause");
				if (avstand < dist[nx][ny]) {
					dist[nx][ny] = avstand;
					pq.push({ avstand,{ nx,ny } });
				}
			}
		}
	}
}
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	fill_n((char*)grid, 4000000, '#');
	int row, col;
	cin >> row >> col;
	fori(row) {
		forj(col) {
			char in;
			cin >> in;
			grid[j][i] = in;
		}
	}
	pair<int, int>start;
	cin >> start.dy >> start.dx;
	start.dy--;
	start.dx--;
	cout << dijkstra(start, row, col);
}
