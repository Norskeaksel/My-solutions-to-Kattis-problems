#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		bool yes=1;
		cin >> n;
		string str;
		set<string>myset;
		for (int i = 0; i < n; i++) {
			cin >> str;
			myset.insert(str);
		}
		for (auto i : myset) {
			int nofd = i.size();
			for (int j = 0; j < nofd; j++) {
				string check;
				check = i.substr(0, j);
				if (myset.count(check)&&yes==1 ) {
					cout << "NO\n";
					yes = 0;
					break;
				}
			}
		}
		if(yes) cout << "YES\n";
	}
}