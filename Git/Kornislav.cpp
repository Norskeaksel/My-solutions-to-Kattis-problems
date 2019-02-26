#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int num[4];
	int input;
	for (int i = 0; i < 4; i++) {
		cin >> input;
		num[i] = input;
	}
	for (int i = 1; i < 4; i++) {
		int j = i - 1;
		while (num[j] > num[i]&&j>=0) {
			int temp = num[j];
			num[j] = num[i];
			num[i] = temp;
			j--;
			i--;
		}
	}
	cout << num[0] * num[2];
}