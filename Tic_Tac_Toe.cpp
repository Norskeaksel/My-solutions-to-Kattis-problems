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
char grid[5][5];

int main() {
	int r = 3, c = 3;
	int n;
	cin >> n;
	while (n--) {
		//cin >> r>> c;
		char in;
		int xnr = 0, onr = 0, over = 1;
		fori(r) {
			forj(c) {
				cin >> in;
				if (in == 'X')
					xnr++;
				if (in == 'O')
					onr++;
				if (in == '.')
					over = 0;
				grid[j][i] = in;
			}
		}
		if (xnr > onr + 1 || onr > xnr) {
			cout << "no\n";
			continue;
		}
		int xvictory = 0, ovictory = 0;
		//horizontal victory start
		for (int y = 0; y < r; y++) {
			int inrow = 1;
			for (int x = 1; x < c; x++) {
				if (grid[x][y] == grid[x - 1][y]) {
					inrow++;
					if (inrow == 3) {
						if (grid[x][y] == 'X')
							xvictory++;
						if (grid[x][y] == 'O')
							ovictory++;
						inrow = 1;
					}
				}
				else
					inrow = 1;
			}
		}
		//vectical victory start
		for (int x = 0; x < c; x++) {
			int inrow = 1;
			for (int y = 1; y < r; y++) {
				if (grid[x][y - 1] == grid[x][y]) {
					inrow++;
					if (inrow == 3) {
						if (grid[x][y] == 'X')
							xvictory++;
						if (grid[x][y] == 'O')
							ovictory++;
						inrow = 1;
					}
				}
				else
					inrow = 1;
			}
		}
		// diagonal victory start
		int inrow = 1;
		for (int i = 1; i < 3; i++) {
			if (grid[i][i] == grid[i - 1][i - 1]) {
				inrow++;
				if (inrow == 3) {
					if (grid[i][i] == 'X')
						xvictory++;
					if (grid[i][i] == 'O')
						ovictory++;
				}
			}
		}
			inrow = 1;
			if (grid[0][2] == grid[1][1]) 
				inrow++;
			if(grid[2][0]== grid[1][1])
				inrow++;
				if (inrow == 3) {
					if (grid[1][1] == 'X')
						xvictory++;
					if (grid[1][1] == 'O')
						ovictory++;
				}
			
			/*diagonal victory start
			for (int y = 0; y < r; y++) {
				int inrow = 1;
				for (int x= 0; x < c; x++) {
					if (grid[x+y][x] == grid[x-1+y][x-1]) {
						inrow++;
						if (inrow == 3) {
							if (grid[x][x] == 'X')
								xvictory++;
							else
								ovictory++;
							inrow = 0;
						}
					}
					else
						inrow = 1;
				}
			}
			for (int y = 0; y < c; y++) {
				int inrow = 1;
				for (int x = 0; x < c; x++) {
					if (grid[x][x+y] == grid[x - 1 + y][x-1]) {
						inrow++;
						if (inrow == 3) {
							if (grid[x][x] == 'X')
								xvictory++;
							else
								ovictory++;
							inrow = 0;
						}
					}
					else
						inrow = 1;
				}
			}*/
			if ((xvictory && ovictory) || (xvictory&& xnr != onr + 1) || (ovictory&&xnr != onr))
				cout << "no\n";
			else
				cout << "yes\n";/*if (xvictory == 1)
				cout << "yes\n";
			else if (ovictory == 1)
				cout << "yes\n";
			else if (over == 0)
				cout << "yes\n";
			else
				cout << "yes\n";*/
		}
	}