#include <iostream>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	string text, simon, command;
	for (int i = 0; i < T + 1; i++) {
		getline(cin, text);
		if (text.length() < 10);
		else if (text == "simon says");
		else if (text.substr(0, 10) == "simon says") {
			cout << text.substr(11, text.length());
		}
		cout << endl;
	}
}