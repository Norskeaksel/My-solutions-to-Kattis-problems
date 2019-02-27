#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double n, divisor = 0, a, dividend = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a != -1) dividend += a;
		if (a == -1) divisor--;
		divisor++;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(16);
	cout << dividend / divisor << endl;
}