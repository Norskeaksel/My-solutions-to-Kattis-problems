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
char grid[100][100];
void check(char grid[100][100], int x, int y) {
	if (grid[x - 1][y - 2] == 'k' || grid[x + 1][y - 2] == 'k' || grid[x + 2][y - 1] == 'k' || grid[x + 2][y + 1] == 'k' || grid[x + 1][y + 2] == 'k' || grid[x - 1][y + 2] == 'k' || grid[x - 2][y - 1] == 'k' || grid[x - 2][y + 1] == 'k') {
		cout << "invalid";
		exit(0);
	}
}
int main() {
	fill_n((char*)grid, 10000, 'X');
	char in;
	int ks=0;
	for (int y = 3; y < 8; y++) {
		for(int x=3;x<8;x++){
			cin >> in;
			if (in == 'k')
				ks++;
			grid[x][y] = in;
		}
	}
	if (ks != 9) {
		cout<<"invalid";
		exit(0);
	}

	for (int y = 3; y < 8; y++) {
		for (int x = 3; x < 8; x++) {
			if (grid[x][y] == 'k')
				check(grid, x, y);
		}
	}
	cout << "valid";
}