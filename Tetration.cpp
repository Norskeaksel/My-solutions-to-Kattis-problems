#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double d;
	cin >> d;
	cout << setprecision(20) << pow(d, (1 / d)) << endl;
}
