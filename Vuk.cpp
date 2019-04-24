#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define ll long long
#define double long double
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

int dist[567][567];
int copydist[567][567];
char grid[567][567];
char copygrid[567][567];

void bfs(vector<pair<int, int>>starts) {
	queue<pair<int, int>>Q;
	for (int i = 0; i < starts.size(); i++) {
		Q.push(starts[i]);
		dist[starts[i].dx][starts[i].dy] = 0;
	}
	int avstand = 0;
	while (!Q.empty()) {
		int x = Q.front().dx;
		int y = Q.front().dy;
		Q.pop();
		grid[x][y] = '#';
		avstand = dist[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			if (grid[nx][ny]!='#') {
				if (avstand + 1 < dist[nx][ny]) {
					dist[nx][ny] = avstand + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
}
struct spot {
	int dx;
	int dy;
	int depth;
};
bool operator <(spot a, spot b) {
	return (a.depth < b.depth);
}
int done[567][567] = {};
int greatestDist(pair<int,int>start,pair<int,int>goal) {
	spot begin = { start.dx,start.dy,dist[start.dx][start.dy] };
	priority_queue<spot>pq;
	pq.push(begin);
	done[start.dx][start.dy] = 1;
	int truedeep = 999;
	while (!pq.empty()) {
		int x = pq.top().dx;
		int y = pq.top().dy;
		//cout << x << " " << y << " " << dist[x][y]<<endl;
		int deepest = pq.top().depth;
		pq.pop();
		deepest = min(deepest, dist[x][y]);
		truedeep = min(deepest, truedeep);
		if (x == goal.dx && y==goal.dy)
			return truedeep;
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			if (!done[nx][ny]++&&dist[nx][ny]<999) {
				pq.push({ nx,ny,dist[nx][ny] });
			}
		}
	}
}
int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int col, row;
	fill_n((char*)grid, 567 * 567, '#');
	fill_n((int*)dist, 567 * 567, 999);
	cin >>  row>>col;
	pair<int, int> start, goal, tree;
	vector<pair<int, int>>trees, vecstart;
	fory(row) {
		forx(col) {
			char c;
			cin >> c;
			grid[x][y] = c;
			if (c == 'V') {
				start.dx = x;
				start.dy = y;
				vecstart.push_back(start);
			}
			if (c == '+') {
				tree.dx = x;
				tree.dy = y;
				trees.push_back(tree);
			}
			if (c == 'J') {
				goal.dx = x;
				goal.dy = y;
			}
		}
	}
	bfs(trees);
	/*fory(row) {
		forx(col) 
			cout << dist[x][y] << " ";
		cout << endl;
	}*/
	cout<< greatestDist(start, goal);
}