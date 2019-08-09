#include <iostream>
using namespace std;
#define fori(n) for (int i=0;i<n;i++)

int main() {
	long long sum = 1;
	int add = 1;
	int t;
	cin >> t;
	fori(t) {
		if (i % 2)
			add++;
		sum += add;
	}
	cout << sum;
}