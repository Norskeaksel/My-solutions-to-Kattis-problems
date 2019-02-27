#include<iostream>
#include<utility>
#include <string>
#include <iomanip>
using namespace std;
pair<int, int>grid[1234][1234];
void dfs(pair<int, int>grid[1234][1234], int x, int y, int color, int start) {
	if (grid[x][y].second == 0) {
		grid[x][y].second = color;
		for (int i = 0; i < 4; i++) {
			int nx = x + (i == 0) - (i == 1);
			int ny = y + (i == 2) - (i == 3);
			if (grid[nx][ny].first == start && grid[nx][ny].second == 0)
				dfs(grid, nx, ny, color, start);
		}
	}
}
int main() {
	fill_n((int*)grid, 1234 * 1234 * 2, -2);
	int r, c;
	cin >> r >> c;
	for (int y = 1; y <= r; y++) {
		string tall;
		cin >> tall;
		for (int x = 1; x <= c; x++) {
			grid[x][y].first = tall[x - 1] - '0';
			grid[x][y].second = 0;
		}
	}
	int color = 1;
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			if (grid[x][y].second == 0) {
				dfs(grid, x, y, color, grid[x][y].first);
				//cout << color << " ";
				color++;

			}
		}
	}
	/*for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cout <<setw(3)<< grid[x][y].second << " ";
		}
		cout << endl;
	}*/
	int t;
	cin >> t;
	while (t--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		string svar;
		svar = grid[c1][r1].first ? "decimal" : "binary";
		if (grid[c1][r1].second == grid[c2][r2].second)
			cout << svar << endl;
		else
			cout << "neither\n";
	}
}