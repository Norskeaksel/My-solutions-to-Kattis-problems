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
pair<char,char> grid[123][123];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, c, n;
		cin >> r >> c >> n;
		fill_n((char*)grid, 123 * 123, 'X');
		char in;
		for (int y = 1; y <= r; y++) {
			for (int x = 1; x <= c; x++) {
				cin >> in;
				grid[x][y].first = in;
				grid[x][y].second = in;
			}
		}
		while (n--) {
			for (int y = 1; y <= r; y++) {
				for (int x = 1; x <= c; x++) {
					for (int i = 0; i < 4; i++) {
						int dx = x + (i == 0) - (i == 1);
						int dy = y + (i == 2) - (i == 3);
						if (grid[x][y].first == 'R') {
							if (grid[dx][dy].first == 'S')
								grid[dx][dy].second = 'R';
						}
						else if (grid[x][y].first == 'S') {
							if (grid[dx][dy].first == 'P')
								grid[dx][dy].second = 'S';
						}
						else if (grid[x][y].first == 'P') {
							if (grid[dx][dy].first == 'R')
								grid[dx][dy].second = 'P';
						}
					}
				}
			}
			for (int y = 1; y <= r; y++) 
				for (int x = 1; x <= c; x++) 
					grid[x][y].first = grid[x][y].second;
		}
		for (int y = 1; y <= r; y++) {
			for (int x = 1; x <= c; x++) {
				cout << grid[x][y].first;
			}
			cout << endl;
		}
	}
}