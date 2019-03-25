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
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
int grid[300][300];
void modifiedDFS(int grid[300][300], int xstart, int ystart, vector<int>&svar, int& end, int &possible) {
	if (end == 0) {
		for (int i = 0; i < 4; i++) {
			if (end == 1)
				break;
			int dx = xstart + (i == 0) - (i == 1);
			int dy = ystart + (i == 2) - (i == 3);
			if (grid[dx][dy] == grid[xstart][ystart]) {
				grid[xstart][ystart] = -2;
				//cout << grid[dx][dy] << " ";
				svar.push_back(grid[dx][dy]);
				grid[dx][dy] = -2;
				xstart += (dx - xstart) * 2;
				ystart += (dy - ystart) * 2;
				if (grid[xstart][ystart] == -1) {
					end = 1;
					return;
				}
				if (grid[xstart][ystart] == -2) {
					end = 1;
					possible = 0;
					return;
				}
				modifiedDFS(grid, xstart, ystart, svar, end, possible);
			}
		}
	}
}
int main() {
	int r, c;
	cin >> r >> c;
	fill_n((int*)grid, 300 * 300, -2);
	int in;
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> in;
			grid[x][y] = in;
		}
	}
	/*for (int y = 0; y <= r+1; y++) {
		for (int x = 0; x <= c+1; x++) {
			cout<<grid[x][y]<<" ";
		}
		cout << endl;
	}*/
	int ystart, xstart;
	vector<int>svar;
	cin >> ystart >> xstart;
	if (grid[xstart][ystart] == -2)
		cout << "impossible\n";
	else {
		vector<int> svar;
		int possible = 1;
		int end = 0;
		modifiedDFS(grid, xstart, ystart, svar, end, possible);
		if (possible) {
			for (int i = svar.size() - 1; i >= 0; i--) {
				cout << svar[i] << " ";
			}
		}
		else
			cout << "impossible\n";
	}
}