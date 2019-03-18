#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> cheat;
	cheat.insert(6);
	cheat.insert(28);
	cheat.insert(496);
	cheat.insert(8128);
	cheat.insert(33550336);
	int num;
	while (cin >> num) {
		if (cheat.count(num)) {
			cout << num << " perfect\n";
			continue;
		}
		int check = 1;
		for (auto i : cheat) {
			if (check) {
				for (int j = -2; j <= 2; j++) {
					if (!j)
						j++;
					if (num == i + j) {
						cout << num << " almost perfect\n";
						check = 0;
					}
				}
			}
		}
		if (!check)
			cout << num << " not perfect\n";
	}
}
