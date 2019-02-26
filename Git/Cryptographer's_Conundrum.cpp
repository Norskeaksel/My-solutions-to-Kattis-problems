#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int counter = 0;
	for (int i = 0; i < str.size(); i+=3) {
		if (str[i] != 'P')
			counter++;
	}
	for (int i = 1; i < str.size(); i += 3) {
		if (str[i] != 'E')
			counter++;
	}
	for (int i = 2; i < str.size(); i += 3) {
		if (str[i] != 'R')
			counter++;
	}
	cout << counter << endl;
}