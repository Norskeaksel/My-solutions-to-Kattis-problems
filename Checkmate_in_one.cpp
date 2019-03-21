#include <iostream>
#include <string>
using namespace std;
int main() {
	string stuff;
	char a;
	int Ri, Rj, Ki, Kj, ki, kj;
	for (int i = 0; i < 8; i++) {
		cin >> stuff;
		for (int j = 0; j < 8; j++) {
			a = stuff[j];
			if (a == 'R') {
				Ri = i;
				Rj = j;
			}
			if (a == 'K') {
				Ki = i;
				Kj = j;
			}
			if (a == 'k') {
				ki = i;
				kj = j;
			}
		}
	}
	if (ki == 0 && Ki == 2 && kj == Kj && Rj != kj && Rj != kj - 1 && Rj != kj + 1) cout << "Yes\n";
	else if (kj == 0 && Kj == 2 && ki == Ki && Ri != ki && Ri != ki - 1 && Ri != ki + 1) cout << "Yes\n";
	else if (ki == 7 && Ki == 5 && kj == Kj && Rj != kj && Rj != kj - 1 && Rj != kj + 1) cout << "Yes\n";
	else if (kj == 7 && Kj == 5 && ki == Ki && Ri != ki && Ri != ki - 1 && Ri != ki + 1) cout << "Yes\n";

	else if (ki == 0 && Ki == 2 && kj == 0 && Kj == 1 && Rj != kj && Rj != Kj)cout << "Yes\n";
	else if (ki == 7 && Ki == 5 && kj == 0 && Kj == 1 && Rj != kj && Rj != Kj)cout << "Yes\n";
	else if (ki == 0 && Ki == 2 && kj == 7 && Kj == 6 && Rj != kj && Rj != Kj)cout << "Yes\n";
	else if (ki == 7 && Ki == 5 && kj == 7 && Kj == 6 && Rj != kj && Rj != Kj)cout << "Yes\n";

	else if (ki == 0 && Ki == 1 && kj == 0 && Kj == 2 && Ri != 1)cout << "Yes\n";
	else if (ki == 7 && Ki == 6 && kj == 0 && Kj == 2 && Ri != 6)cout << "Yes\n";
	else if (ki == 0 && Ki == 1 && kj == 7 && Kj == 5 && Ri != 1)cout << "Yes\n";
	else if (ki == 7 && Ki == 6 && kj == 7 && Kj == 5 && Ri != 6)cout << "Yes\n";
	else cout << "No\n";
}