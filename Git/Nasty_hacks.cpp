#include <iostream>
using namespace std;
int main() {
	int n, a, b, c;
	cin >> n;
	int foo[100];
		for (int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			if (a > b - c) {
				foo[i] = 1;
			}
			else if (a == b - c) {
				foo[i] = 2;
			}
			else if (a < b - c) {
				foo[i] = 3;
			}
		}
		for (int j = 0; j < n; j++) {
			a = foo[j];
			switch (a)
			{
			case 1:
				cout << "do not advertise\n";
				break;
			case 2:
				cout << "does not matter\n"; 
				break;

			case 3:
				cout << "advertise\n";
				break;
			}
		}
}