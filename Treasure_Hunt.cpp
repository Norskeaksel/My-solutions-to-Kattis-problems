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
char grid[234][234];
void go(char grid[234][234], char dir, int counter=0, int xstart = 1, int ystart = 1) {
	if (dir == 'N'){
		grid[xstart][ystart] = 'B';
		go(grid,  grid[xstart][ystart - 1], ++counter, xstart, ystart - 1);
	}
	if (dir == 'S') {
		grid[xstart][ystart] = 'B';
		go(grid, grid[xstart][ystart + 1], ++counter, xstart, ystart + 1);
	}
	if (dir == 'W') {
		grid[xstart][ystart] = 'B';
		go(grid, grid[xstart-1][ystart], ++counter, xstart-1, ystart);
	}
	if (dir == 'E') {
		grid[xstart][ystart] = 'B';
		go(grid, grid[xstart + 1][ystart], ++counter, xstart + 1, ystart);
	}
	if (dir == 'X') {
		cout << "Out\n";
		exit(0);
	}
	if (dir == 'T') {
		cout << counter;
		exit(0);
	}
	if (dir == 'B') {
		cout << "Lost\n";
		exit(0);
	}
}
int main() {
	int r, c;
	cin >> r >> c;
	char in;
	fill_n((char*)grid, 234 * 234, 'X');
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> in;
			grid[x][y] = in;
		}
	}
	go(grid, grid[1][1]);
}