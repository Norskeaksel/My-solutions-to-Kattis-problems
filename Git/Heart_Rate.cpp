#include<iostream>
using namespace std;
int main() {
	int n;
	double b,p;
	cin >> n;
	while (n--) {
		cin >> b >> p;
		cout << 60 * (b - 1) / p << " " << 60 * b / p << " " << 60 * (b + 1) / p << endl;
	}
}