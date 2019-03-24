#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d = abs(a - b);
	int e = abs(b - c);
	int f = max(d, e);
	cout << f - 1 << endl;
}