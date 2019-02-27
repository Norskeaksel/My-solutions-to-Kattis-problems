#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a = 1, svar = 0,temp=1e9;
		while (1) {
			cin >> a;
			if (a == 0)break;
			if (a > 2 * temp)svar += a - 2 * temp;
			temp = a;
		}
		cout << svar << endl;
	}
}