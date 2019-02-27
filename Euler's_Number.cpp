#include<iostream>
#include <iomanip> 
using namespace std;
inline long long Factorial(long long x) {
	return (x == 1 ? x : x * Factorial(x - 1));
}

int main() {
	int n;
	cin >> n;
	double svar = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 21)
			break;
		svar += 1 / (double)Factorial(i);
	}
	cout << setprecision(14) << svar << endl;
}