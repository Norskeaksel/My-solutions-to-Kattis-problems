#include <iostream>
using namespace std;

int main() {
	long long a, b, svar = 1;
	cin >> a >> b;
	if (a % 2 == 1) cout << 0 << endl;
	else {
		for (int i = 0; i < b; i++) {
			svar = a / 2 * svar%a;
		}
		cout << svar << endl;
	}
}