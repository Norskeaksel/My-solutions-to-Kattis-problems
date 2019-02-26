#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string a,b;
	for (int i = 0; i < n; i++) {
		cin >> a>>b;
		cout << a << endl << b << endl;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == b[j])cout << ".";
			else cout << "*";
		}
		cout << endl;
	}
}