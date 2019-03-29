#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		int svar = 1;
		for (int i = 1; i < n; i++) {
			svar *= 2;
			svar++;
		}
		cout << svar << endl;
	}
}