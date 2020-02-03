#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string champion;
	string thore = "ThoreHusfeldt";
	int index;
	while (n--) {
		string same = "";
		string candidate;
		cin >> candidate;
		if (candidate == thore)
			break;
		for (int i = 0; i < thore.size(); i++) {
			if (candidate[i] == thore[i])
				same += thore[i];
			else if (same == thore) {
				cout << "Thore sucks\n";
				exit(0);
			}
			else {
				same += thore[i];
				break;
			}
		}
		if (same.size() > champion.size())
			champion = same;
	}
	if (champion.size() == 0)
		cout << "Thore is awesome\n";
	else if (champion.size() == thore.size())
		cout << "Thore sucks\n";
	else
		cout << champion;
}
