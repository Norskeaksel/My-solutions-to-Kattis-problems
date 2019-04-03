#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main() {
	string str;
	vector<string>text;
	set<string>check;
	while (cin >> str) {
		string ny="";
		for (int j = 0; j < str.size(); j++) {
			ny+=tolower(str[j]);
		}
		if (check.count(ny)) {
			text.push_back(".");
		}
		else {
			text.push_back(ny);
			check.insert(ny);
		}
	}
	for (auto i : text) {
		cout << i << " ";
	}
}