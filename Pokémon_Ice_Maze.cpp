#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
char grid[2000][2000];
int dist[2000][2000];
#define dx first
#define dy second
void bfs(char grid[2000][2000], pair<int, int>goal, int dist[2000][2000]) {
	queue<pair<int, int>>Q;
	Q.push(goal);
	int avstand = 0;
	while (!Q.empty()) {
		int x = Q.front().dx;
		int y = Q.front().dy;
		grid[x][y] = '#';
		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j <8 ; j++)
				cout << grid[j][i];
			cout << endl;
		}
		system("pause");*/
		Q.pop();
		avstand = dist[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			if (grid[nx][ny] != '#') {
				if (avstand + 1 < dist[nx][ny]) {
					dist[nx][ny] = avstand + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	fill_n((char*)grid, 2000 * 2000, '#');
	fill_n((int*)dist, 4000000, 99999999);
	int c, r;
	cin >> c >> r;
	char ting;
	pair<int, int> goal;
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> ting;
			if (ting == 'M') {
				goal.dx = x;
				goal.dy = y;
			}
			grid[x][y] = ting;
		}
	}
	/*for (int y = 0; y < r + 2; y++) {
		for (int x = 0; x < c + 2; x++) {
			cout << grid[x][y];
		}
		cout << endl;
	}*/
	dist[goal.dx][goal.dy] = 0;
	bfs(grid, goal, dist);
	for (int y = 1; y < r + 1; y++) {
	for (int x = 1; x < c + 1; x++) {
		if (dist[x][y] == 99999999)
			dist[x][y] = -1;
		cout << dist[x][y]<<" ";
	}
	cout << endl;
}
}