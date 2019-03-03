#include <iostream>
#include <math.h> 
using namespace std;
int main() {
	long long t;
	long double p, r, f;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p >> r >> f;
		int counter = 0;
		long long s = p;
		while (s <= f) {
			counter++;
			s *= r;
		}
		cout << counter << endl;
	}
}