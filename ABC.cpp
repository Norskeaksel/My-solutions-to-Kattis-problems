#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[4];
	int a, b, c;
	cin >> a >> b >> c;
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr, arr + 3);
	char A;
	for (int i = 0; i < 3; i++) {
		cin >> A;
		if (A == 'A') cout << arr[0] << " ";
		else if (A == 'B') cout << arr[1] << " ";
		else if (A == 'C')  cout << arr[2] << " ";
	}
}