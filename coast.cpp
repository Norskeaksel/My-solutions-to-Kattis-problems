#include <iostream>
#include <string>
using namespace std;
int grid[1234][1234];
void dfs(int grid[1234][1234],int xstart=1,int ystart=1) {
	if (grid[xstart][ystart] == 0) {
		grid[xstart][ystart] = 2;
		/*for (int y = 0; y < 4 + 4; y++) {
			for (int x = 0; x <4  + 4; x++) {
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");*/
		for (int i = 0; i < 4; i++) {
			int nyx = xstart + (i == 0) - (i == 1);
			int nyy = ystart + (i == 2) - (i == 3);
			if (grid[nyx][nyy] == 1) {
				grid[xstart][ystart] = 3;
			}
			if (grid[nyx][nyy] == 0) {
				dfs(grid, nyx, nyy);
			}
		}
	}
}
int main() {
	fill_n((int*)grid, 1234 * 1234, 8);
	int r, c;
	cin >> r >> c;
	for (int y = 1; y <= r + 2; y++) {
		for (int x = 1; x <= c + 2; x++) {
			grid[x][y] = 0;
		}
	}
	for (int y = 2; y <= r + 1; y++) {
		string str;
		cin >> str;
		for (int x = 2; x <= c + 1; x++) {
			grid[x][y] = str[x - 2] - '0';
		}
	}
	/*for (int y = 0; y < r + 4; y++) {
		for (int x = 0; x < c + 4; x++) {
			cout << grid[x][y];
		}
		cout << endl;
	}*/
	dfs(grid);
	int svar = 0;
	for (int y = 0; y < r + 4; y++) {
		for (int x = 0; x < c + 4; x++) {
			if (grid[x][y] == 3) {
				for (int i = 0; i < 4; i++) {
					int nyx = x + (i == 0) - (i == 1);
					int nyy = y + (i == 2) - (i == 3);
					if (grid[nyx][nyy] == 1) {
						svar++;
					}
				}
			}
		}
	}
	cout << svar << endl;
}
