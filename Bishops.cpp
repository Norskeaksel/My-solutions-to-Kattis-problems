#include <iostream>
using namespace std;
int main() {
	int i;
	while (cin >> i) {
		if (i < 1)
			cout << 0 << endl;
		else if (i == 1)
			cout << i<<endl;
		else
			cout << (i - 1) * 2 << endl;
	}
}