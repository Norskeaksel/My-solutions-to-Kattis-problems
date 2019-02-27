#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int a;
	cin >> a;
	string spiller;
	vector<string>lag,dec,inc;
	for (int i = 0; i < a; i++) {
		cin >> spiller;
		lag.push_back(spiller);
	}
	dec = lag;
	sort(dec.rbegin(), dec.rend());
	inc = lag;
	sort(inc.begin(), inc.end());
	if (dec == lag) cout << "DECREASING\n";
	else if (inc == lag)cout << "INCREASING\n";
	else cout << "NEITHER\n";
}