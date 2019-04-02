#include <iostream>
#include<string>
using namespace std;

int main() {
	char** a2d = new char*[8];
	for (int i = 0; i < 8; i++)
		a2d[i] = new char[8];
	string line;
	for (int y = 0; y < 8; y++) {
		getline(cin, line);
		for (int x = 0; x < 8; x++) {
			a2d[x][y] = line[x];
		}
	}
	int nofq = 0;
	for (int i = 0; i < 8; i++) {
		int xsquares = 9, ysquares = -1;
		for (int j = 0; j < 8; j++) {
			xsquares--;
			ysquares++;
			if (a2d[i][j] == '*') {
				nofq++;
				for (int a = 0; a < 8; a++) {
					if (a2d[i][a] == '*'&&a != j) {
						cout << "invalid\n";
						exit(0);
					}
				}
				for (int a = 0; a < 8; a++) {
					if (a2d[a][j] == '*' && a != i) {
						cout << "invalid\n";
						exit(0);
					}
				}
				for (int a = 1; i + a < 8 && j + a < 8; a++) {
					if (a2d[a+i][a+j] == '*') {
						cout << "invalid\n";
						exit(0);
					}
				}

				for (int a = 1; i - a >-1 && j + a < 8; a++) {
					if (a2d[-a + i][a + j] == '*') {
						cout << "invalid\n";
						exit(0);
					}
				}
			}

		}
	}
	if (nofq != 8) cout << "invalid\n";
	else cout << "valid\n";
}