#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int apples, bag, k = 1;
	cin >> apples >> bag;
	int appleright, appleleft;
	if (bag >= apples) k = apples + 1;
	else {
		while (apples > 0) {
			appleright = apples;
			appleleft = appleright - (appleright+bag-1) / bag;
			apples = appleleft;
			k++;
		}
	}
	cout << k << endl;
}
