#include <iostream>
using namespace std;
int main() {
	int n;
	int x;
	int svar = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
			if (x < 0) {
				svar++;
			}
	}
	cout << svar <<endl;
}

