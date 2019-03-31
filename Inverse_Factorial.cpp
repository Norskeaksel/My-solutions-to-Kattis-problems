#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define fori(n) for (int i = 0; i < (n); i++)

int main() {
	cin.sync_with_stdio(false);
	string str;
	int a, b, c;
	cin >> str;
	c = str.size();
	if (c < 9) {
		int svar = 1, i = 2, n;
		n = stoi(str);

		while (svar < n) {
			svar = svar * i;
			i++;
		}
		cout << i - 1 << endl;
		return 0;
	}

	double svar = 0, i = 1;

	while (svar < c-1) {
		svar = svar + log10 (i);
		i++;
	}
	cout << i - 1 << endl;
	return 0;
}