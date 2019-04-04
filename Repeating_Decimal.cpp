#include <iostream>
using namespace std;
int main() {
	int a, b, c,svar;
	while (cin >> a) {
		cin >> b >> c;
		a *= 10;
		cout << "0.";
		for (int i = 0; i < c; i++) {
			svar = a / b;
			cout << svar;
			a = (a%b)*10;
		}
		cout << endl;
	}
}