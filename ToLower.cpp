#include <iostream>
#include<vector>
#include <string>
using namespace std;
int main() {
	int t,n,score=0;
	cin >> t >> n;
	while (t--) {
		vector<string>tests;
		bool check=1;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			//tests.push_back(str);
			if (str.size() > 1) {
				for (int j = 1; j < str.size(); j++) {
					if (str[j] < 97)
						check = 0;
				}
			}
		}
		if (check)
			score++;
	}
	cout << score << endl;
}
