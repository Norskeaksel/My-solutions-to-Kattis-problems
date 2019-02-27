#include <iostream>
using namespace std;
int main() {
	int svar = 0;
	int vinner = 0;
	int a, b, c, d;
	for (int i = 1; i < 6; i++) {
		cin >> a >> b >> c >> d;
		int nyttsvar = a + b + c + d;
		if (nyttsvar > svar) {
			svar = nyttsvar;
			vinner = i;
		}
	}
	cout << vinner <<" " << svar<< endl;
}