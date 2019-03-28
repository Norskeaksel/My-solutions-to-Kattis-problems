#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x>> y;
	if ((2*x + y) % 2)
		cout << "impossible\n";
	else
		cout << "possible\n";
}