#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long fac;
	int counter = 0;
	cin >> fac;
	while (fac > 1) {
		int i = 2;
		while (1) {
			if (fac / i == (fac + i - 1) / i) {
				fac /= i;
				counter++;
				break;
			}
			if (i > sqrt(fac) && counter == 0) {
				cout << 1 << endl;
				exit(0);
			}
			i+=2;
			if (i == 4)
				i--;
		}
	}
	cout << counter<<endl;
}