#include <iostream>
#include <vector>
using namespace std;
int main() {
	int t, n, x;
	cin >> t;
	while (t--) {
		vector<int>g;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			g.push_back(x);
		}
		g.push_back(-1);
		g.insert(g.begin() + 0, -1);
		for (int i = 0; i < n; i++) {
			if (g[i]> g[i + 1]&& g[i-1]>g[i+1]){
				cout << i+1  << endl;
				break;
			}
			if (g[i]> g[i + 1]){
				cout << i  << endl;
				break;
			}
		}
	}
}