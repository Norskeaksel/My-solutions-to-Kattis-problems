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
#pragma warning(disable:4996)

struct spot {
	int dx;
	int dy;
	int depth;
};
bool operator <(spot a, spot b) {
	return (a.depth > b.depth);
}
int grid[1234][1234];
int done[1234][1234] = {};
int bfs(int end,int row,int col,spot start = { 0,0,0 }) {
	priority_queue<spot>pq;
	pq.push(start);
	//ll deapest=grid[start.dx][start.dy];
	int truedeep = 0;
	while (!pq.empty()) {
		int x = pq.top().dx;
		int y = pq.top().dy;
		int deepest = pq.top().depth;
		//cout << x << " " << y << " " << deapest << endl;
		//system("pause"); finn ut hvordan du velger punktet med minst dybde
		done[x][y] = 1;
		pq.pop();
		deepest = max(deepest, grid[x][y]);
		truedeep = max(deepest, truedeep);
		//cout << truedeep << " ";
		if (x == end)
			return truedeep;
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			//cout << nx << " " << ny << " " << grid[nx][ny]<<endl;
			if (nx!=-1&&ny!=-1&&ny!=row&& !done[nx][ny]) {
				//if (avstand + 1 < dist[nx][ny]) {
					//dist[nx][ny] = avstand + 1;
				pq.push({ nx,ny,grid[nx][ny] });//hvorfor går dette galt?
				//}
			}
		}
	}
}
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	int row, col;
	cin >> row >> col;
	int end = col + 1;
	vector<spot>starts;
	for (int y = 0; y < row;y++) {
		grid[0][y] = 0;
		starts.push_back({ 1, y,0 });
		for (int x = 1; x < col + 1; x++) {
			int a;
			cin >> a;
			grid[x][y] = a;
			/*if (x == 1) {
				graph[0][y] = a;
			}*/
		}
	}
	/*for (int y = 0; y < row;y++) {
		for (int x = 0; x < col +1;x++) {
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}*/
	cout << bfs(end,row,col) << endl;
}
