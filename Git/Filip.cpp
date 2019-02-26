#include <iostream>
using namespace std;

int main() {
	int a1, b1, a2, b2, forste1, andre1, tredje1, forste2, andre2, tredje2;
	cin >> a1 >> b1;
	forste1 = a1 % 10;
	andre1 = ((a1 - forste1) / 10) % 10;
	tredje1 = (a1 - forste1 - andre1 * 10) / 100;
	a2 = forste1 * 100 + andre1 * 10 + tredje1;

	forste2 = b1 % 10;
	andre2 = ((b1 - forste2) / 10) % 10;
	tredje2 = (b1 - forste2 - andre2 * 10) / 100;
	b2 = forste2 * 100 + andre2 * 10 + tredje2;
	if (b2 > a2) a2 = b2;
	cout << a2 << endl;
}