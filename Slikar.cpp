#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
#define dx first
#define dy second
void bfs(char grid[100][100], vector<pair<int, int>>start, int dist[100][100], int fire = 0) {
	queue<pair<int, int>>Q;
	for (int i = 0; i < start.size(); i++) {
		Q.push(start[i]);
		dist[start[i].dx][start[i].dy] = 0;
	}
	int avstand = 0;
	while (!Q.empty()) {
		int x = Q.front().dx;
		int y = Q.front().dy;
		grid[x][y] = 'X';
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
			if (fire && grid[nx][ny] == 'D');
			else if (grid[nx][ny] != 'X') {
				if (avstand + 1 < dist[nx][ny]) {
					dist[nx][ny] = avstand + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	char grid[100][100], copy1[100][100], copy2[100][100];
	fill_n((char*)grid, 10000, 'X');
	int r, c;
	cin >> r >> c;
	char ting;
	pair<int, int> start, den, vann;
	vector<pair<int, int>>waterstarts;
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> ting;
			if (ting == 'S') {
				start.dx = x;
				start.dy = y;
			}
			if (ting == 'D') {
				den.dx = x;
				den.dy = y;
			}
			if (ting == '*') {
				vann.dx = x;
				vann.dy = y;
				waterstarts.push_back(vann);
			}
			grid[x][y] = ting;
		}
	}
	copy_n((char*)grid, 10000, (char*)copy1);
	copy_n((char*)grid, 10000, (char*)copy2);
	/*for (int y = 0; y <= r + 1; y++) {
		for (int x = 0; x <= c + 1; x++)
			cout << grid[x][y];
		cout << endl;
	}GOOD*/

	int dist[100][100];
	fill_n((int*)dist, 10000, 999);
	vector<pair<int, int>>vecstart;
	vecstart.push_back(start);
	bfs(grid, vecstart, dist);
	/*for (int y = 0; y <= r + 1; y++) {
		for (int x = 0; x <= c + 1; x++)
			cout << dist[x][y] << " ";
		cout << endl;
	}*/

	int herodist[100][100];
	copy_n((int*)dist, 10000, (int*)herodist);

	int waterdist[100][100];
	fill_n((int*)dist, 10000, 999);
	bfs(copy1, waterstarts, dist, 1);
	/*for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cout << dist[x][y] << " ";
		}
		cout << endl;
	}*/
	copy_n((int*)dist, 10000, (int*)waterdist);
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			if (waterdist[x][y] <= herodist[x][y] && waterdist[x][y] < 99) {
				copy2[x][y] = 'X';
			}
			//cout << copy2[x][y];
		}
		//cout << endl;
	}
	fill_n((int*)dist, 10000, 999);
	bfs(copy2, vecstart, dist);
	if (dist[den.dx][den.dy] < 999)
		cout << dist[den.dx][den.dy] << endl;
	else
		cout << "KAKTUS\n";
}
