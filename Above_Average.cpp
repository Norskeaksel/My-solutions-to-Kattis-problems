#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
	int t;
	vector<int>grade;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double k, total=0, ave;
		for (int i = 0; i < n; i++) {
			cin >> k;
			grade.push_back(k);
			total += k;
		}
		ave = total / n;
		double above = 0;
		for (int i = 0; i < n; i++) {
			if ( grade[i]>ave) above++;
		}
		double svar = above * 100 / n;
		cout << fixed<<setprecision(3) << svar << "%\n";
		grade.clear();
	}
}