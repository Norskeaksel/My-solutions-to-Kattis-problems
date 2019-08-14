#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v,ans;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int last = -1;
	for (auto i:v) {
		if (i > last) {
			last= i;
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (auto i:ans)
		cout << i << " ";
}