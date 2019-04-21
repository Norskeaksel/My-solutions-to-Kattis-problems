#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//misforstått oppgave, oppgaven er å skrive alfabetet
void placeChar(string &str, char c, int i, bool front = true) {
	if (front) {
		str.erase(str.begin() + i);
		/*while (c > str[i + 1]) {
			swap(str[i + 1], str[i]);
			i++;*/
	}
	else {
		while (c < str[i - 1]) {
			swap(str[i - 1], str[i]);
			i--;
		}
	}
}
int main() {
	string str;
	cin >> str;
	string copy = 'a' + str;
	str += 'z';
	int countera = 0, counterb = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] > str[i + 1]) {
			str.erase(str.begin() + i);
			//placeChar(str, str[i], i);
			//cout << str << endl;
			countera++;
			i = -1;
		}
	}
	for (int i = copy.size() - 1; i > 0; i--) {
		if (copy[i] < copy[i - 1]) {
			//placeChar(copy, copy[i], i,false);
			copy.erase(copy.begin() + i);
			cout << copy << endl;
			counterb++;
			i = copy.size();
		}
	}
	cout << min(countera, counterb);
}