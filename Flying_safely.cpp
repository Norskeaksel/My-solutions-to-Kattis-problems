#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int p;
		int t;
		cin >> p>>t;
		int dummy;
		cout << p - 1 << endl;
		for (int i = 0; i <t * 2; i++)
			cin >> dummy;
	}
}