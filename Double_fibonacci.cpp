#include <iostream>
#include <string>
using namespace std;
int fibonacci(int n) {
	if (n == -1) return 0;
	else if (n == 0) return 1;
	else {
		int a = 0;
		int b = 1;
		for (int x = 0; x < n; x++) {
			int temp = b;
			b += a; // b=b+a
			a = temp;
		}
		return b;
	}
}
int main() {
	int k;
	cin >> k;
	cout << fibonacci(k-2) << " " << fibonacci(k-1) << endl;
}