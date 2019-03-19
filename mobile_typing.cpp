#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
int main() {
	map<char, int>mymap;
	for (int i = 0; i < 5; i++) {
		mymap['a' + 3 *	 i] = 2 + i;
		mymap['b' + 3 * i] = (2 + i) * 11;
		mymap['c' + 3 * i] = (2 + i) * 111;
		}
	mymap['t'] = 8;
	mymap['u'] = 88;
	mymap['v'] = 888;
	mymap[' '] = 0;
	mymap['w'] = 9;
	mymap['x'] = 99;
	mymap['y'] = 999;
	mymap['z'] = 9999;
	mymap['p'] = 7;
	mymap['q'] = 77;
	mymap['r'] = 777;
	mymap['s'] = 7777;
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		cout << "Case #" << i << ": ";
		string str;
		getline(cin, str);
		for (int j = 0; j < str.size(); j++) {
				cout << mymap[str[j]];
			if (j < str.size()) {
				string result1, result2;
				ostringstream convert1, convert2;
				convert1 << mymap[str[j]];
				convert2<< mymap[str[j+1]];
				result1 = convert1.str();
				result2 = convert2.str();
				if (result1[0] == result2[0]) { 
					cout << " "; }
			}
		}
		cout << endl;
	}
}