#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	long long test,gjester,a=0, gjestekode;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		vector <long long> kode;
		cin >> gjester;
		for (int j = 0; j < gjester; j++) {
			cin >> gjestekode;
			kode.push_back(gjestekode);
		}
		kode.push_back(pow(2,33));
		sort(kode.begin(), kode.end());
		for (int j = 1; j <= gjester; j++) {
			if (j % 2 == 1 && kode[j] != kode[j - 1]) { cout << "Case #" << i << ": " << kode[j - 1] << endl;
			a = 1;
			break;
			}
			
		}
		if(a=0)cout << "Case #" << i << ": " << kode[kode.size()] << endl;
	}
}