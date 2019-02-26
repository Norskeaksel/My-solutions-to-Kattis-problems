#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	int t;
	cin >> t;
	map< int, string>data;
	while (t--) {
		string first,color;
		cin >> first;
		int str2int,normal;
		char num = first[0];
		if (num < 58) {
			str2int = stoi(first);
			cin >> color;
			data[str2int/2] = color;
		}
		else {
			cin >> normal;
			data[normal] = first;
		}
	}
	for (auto p : data) cout << p.second << endl;
}