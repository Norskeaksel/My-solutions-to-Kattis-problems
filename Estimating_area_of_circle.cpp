#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	while (1) {
		long double in, tot, r;
		cin >> r >> tot >> in;
		if (r == 0 && tot == 0 && in == 0)
			exit(0);
		long double estimate, real;
		estimate = in / tot * r*r * 4;
		real = acos(-1)*r*r;
		cout << fixed << setprecision(14) << real << " ";
		cout << fixed << setprecision(14) << estimate << endl;
	}
}