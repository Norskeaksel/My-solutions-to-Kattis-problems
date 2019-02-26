#include <iostream>
#include <cmath>
#include <math.h> 
#include <iomanip>
using namespace std;
int main() {
	long double x1=1, y1, x2, y2, p,svar;
	cin >> x1;
	while (x1) {
		cin>> y1>> x2>> y2>> p;
		svar = pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p);
		cout << fixed << setprecision(14) << pow(svar, 1 / p)<<endl;
		cin >> x1;
	}
}