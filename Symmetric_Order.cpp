#include <iostream>
#include <string>
#include<vector>
using namespace std;
int main() {
	int n=1;
	int c=1;
	while (1) {
		cin >> n;
		if (n == 0)
			exit(0);
		cout << "SET " << c << endl;;
		c++;
		string str;
		vector<string>vec, copy, svar;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec.push_back(str);
		}
		for (int i = 0; i < n; i += 2) {
			cout << vec[i] << endl;
		}
		if (n % 2) {
			for (int i = n - 2; i > 0; i -= 2)
				cout << vec[i] << endl;
		}
		else {
			for (int i = n - 1; i > 0; i -= 2)
				cout << vec[i] << endl;
		}
	}
}