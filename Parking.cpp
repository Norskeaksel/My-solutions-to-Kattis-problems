#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t,n,x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector <int> coor;
		for (int j = 0; j < n; j++) {
			cin >> x;
			coor.push_back(x);
		}
		sort(coor.begin(), coor.end());
		cout << (coor[coor.size() - 1]  - coor[0]) * 2 << endl;
	}
}