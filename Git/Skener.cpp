#include <iostream>
#include <string>
using namespace std;
int main() {
	int r, c, zr, zc;
	char original[50][50] = {};
	char svar[250][250] = {};
	cin >> r >> c >> zr >> zc;
	string input;
	for (int y = 0; y < r; y++) {
		cin >> input;
		for (int x = 0; x < c; x++) {
			original[x][y] = input[x];
		}
	}
	/*for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cout<<original[x][y];
		}
		cout << endl;
	}*/
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			for (int row = y * zr; row < y*zr + zr; row++) {
				for (int col = x * zc; col < x*zc + zc; col++) {
					svar[col][row] = original[x][y];
				}
			}
		}
	}
	for (int y = 0; y < r*zr; y++) {
		for (int x = 0; x < c*zc; x++) {
			cout << svar[x][y];
		}
		cout << endl;
	}
}