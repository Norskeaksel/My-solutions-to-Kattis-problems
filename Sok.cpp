#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
	double b1, b2, b3,c1,c2,c3;
	cin>> b1>> b2>> b3>> c1>> c2>> c3;
	double p[3];
	p[0] = b1 / c1;
	p[1] = b2 / c2;
	p[2] = b3 / c3;
	auto minmax = minmax_element(begin(p), end(p));
	double smalest = *minmax.first;
	cout <<fixed << setprecision(6) << b1 - c1 * smalest << " ";
	cout << b2 - c2 * smalest << " ";
	cout<< b3 - c3 * smalest;
}