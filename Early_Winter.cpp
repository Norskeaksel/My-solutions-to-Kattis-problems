#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, now,days;
	cin >> n >> now;
	for (int i = 0; i < n; i++) {
		cin >> days;
		if (days <= now) {
			cout << "It hadn't snowed this early in " << i << " years!\n";
				return 0;
		}
	}
	cout << "It had never snowed this early!\n";
}