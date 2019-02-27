#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long double>myvec;
	for (int i = 0; i < n; i++) {
		long double w;
		cin >> w;
		myvec.push_back(w);
	}
	long double b,xi;
	cin >> b;
	while (cin >> xi) {
		long double svar = 0;
		int i = 0;
		svar += myvec[i] * xi;
		for (int j = 1; j < n; j++) {
			cin >> xi;
			svar += myvec[j]* xi;
		}
		svar += b;
		long double divide=0;
		for (int j = 0; j < n; j++)
			divide += myvec[j] * myvec[j];
		svar /= sqrt(divide);
		cout << svar << endl;
	}
}