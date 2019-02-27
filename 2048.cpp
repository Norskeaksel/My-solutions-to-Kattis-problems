#include <iostream>
using namespace std;
int main() {
	int arr[4][4];
	int n;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> n;
			arr[x][y] = n;
		}
	}

	int way;
	cin >> way;
	int counter = 0;
	if (way == 0) {
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 3; x++) {
					if (arr[x][y] == 0) {
						arr[x][y] = arr[x + 1][y];
						arr[x + 1][y] = 0;
					}
				}
			}
		}

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 3; x++) {
				if (arr[x][y] == arr[x + 1][y]) {
					arr[x][y] *= 2;
					arr[x + 1][y] = 0;
				}

				/*if (arr[x][y] == 0) {
					for (int a = x; a < 3; a++) {
						arr[a][y] = arr[x + 1][y];
						arr[x + 1][y] = 0;
					}
				}*/
			}
		}
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 3; x++) {
					if (arr[x][y] == 0) {
						arr[x][y] = arr[x + 1][y];
						arr[x + 1][y] = 0;
					}
				}
			}
		}
	}
	if (way == 2) {
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 3; x++) {
					if (arr[x + 1][y] == 0) {
						arr[x + 1][y] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}

		for (int y = 0; y < 4; y++) {
			for (int x = 3; x > 0; x--) {
				if (arr[x-1][y] == arr[x][y]) {
					arr[x][y] *= 2;
					arr[x-1][y] = 0;
				}
				/*if (arr[x][y] == 0) {
					for (int a = x; a >0; a--) {
						arr[a][y] = arr[x - 1][y];
						arr[x - 1][y] = 0;
					}
				}*/
			}
		}
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 3; x++) {
					if (arr[x + 1][y] == 0) {
						arr[x + 1][y] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}
	}
	if (way == 3) {
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y <3; y++) {
				for (int x = 0; x < 4; x++) {
					if (arr[x][y + 1] == 0) {
						arr[x][y + 1] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}

		for (int y = 3; y > 0; y--) {
			for (int x = 0; x < 4; x++) {
				if (arr[x][y - 1] == arr[x][y]) {
					arr[x][y] *= 2;
					arr[x][y-1] = 0;
				}
				/*if (arr[x][y] == 0) {
					for (int a = y; a >0; a--) {
						arr[x][a] = arr[x][y-1];
						arr[x][y-1] = 0;
					}
				}*/
			}
		}
		for (int t = 0; t < 5; t++) {
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 4; x++) {
					if (arr[x][y + 1] == 0) {
						arr[x][y + 1] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}
	}

	if (way == 1) {
		for (int t = 0; t < 5; t++) {
			for (int y = 3; y > 0; y--) {
				for (int x = 0; x < 4; x++) {
					if (arr[x][y - 1] == 0) {
						arr[x][y - 1] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}

		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 4; x++) {
				if (arr[x][y+1] == arr[x][y]) {
					arr[x][y] *= 2;
					arr[x][y+1] = 0;
				}
				/*if (arr[x][y] == 0) {
					for (int a = y; a <3; a++) {
						arr[x][a] = arr[x][y + 1];
						arr[x][y +1] = 0;
					}
				}*/
			}
		}
		for (int t = 0; t < 5; t++) {
			for (int y = 3; y > 0; y--) {
				for (int x = 0; x < 4; x++) {
					if (arr[x][y - 1] == 0) {
						arr[x][y - 1] = arr[x][y];
						arr[x][y] = 0;
					}
				}
			}
		}
	}
//print resultat
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}