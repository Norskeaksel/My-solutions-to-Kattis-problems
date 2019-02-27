#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	double a, b,svar=0;
	while (t--) {
		cin >> a >> b;
		svar += a * b;
	}
	cout << svar << endl;
}