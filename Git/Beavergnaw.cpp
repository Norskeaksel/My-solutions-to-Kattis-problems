#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	double D=1, v=1;
		while (1) {
		cin >> D >> v;
		if (D == 0 && v == 0)
			break;
		double d3 = D * D*D - 6 * v / acos(-1);
		double d = pow(d3, 1 / 3.0);
		cout << fixed << setprecision(14) << d << endl;;
	}
	return 0;
}