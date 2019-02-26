#include <iostream>
using namespace std;

int main() {
	int n;
	int k;
	cin >> n;
	for (int x = 0; x < n; x++){
		cin >> k;
			if (k % 2 == 0) {
				cout << k << " is even" << endl;
			}
			else {
				cout << k << " is odd" << endl;
			}
	}
}