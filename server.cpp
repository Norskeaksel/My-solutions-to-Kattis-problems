#include <iostream>
using namespace std;
int main() {
	int n, t, tid = 0, svar = 0, task;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> task;
		tid += task;
		if (tid > t) break;
		svar++;
	}
	cout << svar << endl;
}