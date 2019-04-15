#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double a, b, x, y, x2, y2;
		cin >> a >> b;
		x = b + (a - b) / 2;
		y = (a - b) / 2;
		x2 = (a - b) / 2;
		y2 = b + (a - b) / 2;
		if (x >= 0 && y >= 0 && x == int(x) && y == int(y))
			cout << max(x, y) << " " << min(x, y) << endl;
		else if (x2 >= 0 && y2 >= 0 &&x2==int(x2)&&y2==int(y2))
			cout << max(x2, y2) << " " << min(x2, y2) << endl;
		else
			cout << "impossible\n";
	}
}