#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
#define dx first
#define dy second
void bfs(char grid[2000][2000], vector<pair<int, int>>start, int dist[2000][2000], int fire = 0) {
	queue<pair<int, int>>Q;
	for (int i = 0; i < start.size(); i++) {
		Q.push(start[i]);
		dist[start[i].dx][start[i].dy] = 0;
	}
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
			if (grid[nx][ny] == 'G'&&fire == 1);
			else if (grid[nx][ny] != '#') {
				if (avstand + 1 < dist[nx][ny]) {
					dist[nx][ny] = avstand + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
}
char grid[2000][2000], copy1[2000][2000], copy2[2000][2000];
int dist[2000][2000];
int herodist[2000][2000];
int firedist[2000][2000];
int main() {
	fill_n((char*)grid, 4000000, '#');
	int r, c;
	cin >> r >> c;
	char ting;
	pair<int, int> start, g, fire;
	vector<pair<int, int>>firestarts, goals;
	for (int y = 1; y < r + 3; y++) {
		for (int x = 1; x < c + 3; x++) {
			if (y == 1 || x == 1 || y == r + 2 || x == c + 2) {
				grid[x][y] = 'G';
				g.dx = x;
				g.dy = y;
				goals.push_back(g);
			}
			else {
				cin >> ting;
				if (ting == 'J') {
					start.dx = x;
					start.dy = y;
				}
				if (ting == 'F') {
					fire.dx = x;
					fire.dy = y;
					firestarts.push_back(fire);
				}
				grid[x][y] = ting;
			}
		}
	}
	copy_n((char*)grid, 4000000, (char*)copy1);
	copy_n((char*)grid, 4000000, (char*)copy2);
	for (int y = 0; y < r + 4; y++) {
		for (int x = 0; x < c + 4; x++)
			cout << grid[x][y];
		cout << endl;
	}
	fill_n((int*)dist, 4000000, 99999999);
	vector<pair<int, int>>vecstart;
	vecstart.push_back(start);
	bfs(grid, vecstart, dist);
	/*for (int y = 0; y < r + 4; y++) {
		for (int x = 0; x < c + 4; x++)
			cout <<setw(6)<< dist[x][y] << " ";
		cout << endl;
	}*/

	copy_n((int*)dist, 4000000, (int*)herodist);
	fill_n((int*)dist, 4000000, 99999999);
	bfs(copy1, firestarts, dist, 1);
	/*for (int y = 1; y < r+4; y++) {
		for (int x = 1; x < c+4; x++) {
			cout <<setw(6)<< dist[x][y] << " ";
		}
		cout << endl;
	}*/
	copy_n((int*)dist, 4000000, (int*)firedist);
	for (int y = 1; y < r + 4; y++) {
		for (int x = 1; x < c + 4; x++) {
			if (firedist[x][y] <= herodist[x][y]) {
				copy2[x][y] = '#';
			}
			//cout << copy2[x][y];
		}
		//cout << endl;
	}
	fill_n((int*)dist, 4000000, 99999999);
	bfs(copy2, vecstart, dist);
	int sp = 99999999;
	for (auto i : goals) {
		if (dist[i.dx][i.dy] < sp) {
			sp = dist[i.dx][i.dy];
		}
	}
	if (sp < 99999999)
		cout << sp << endl;
	else
		cout << "IMPOSSIBLE\n";
}