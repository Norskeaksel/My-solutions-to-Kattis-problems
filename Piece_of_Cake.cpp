#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int l, h, v;
	cin >> l >> h >> v;
	cout<<max(l - h, h)*max(l - v, v) * 4;
}
