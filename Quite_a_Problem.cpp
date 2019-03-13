#include<iostream>
#include<string>
using namespace std;
int main() {
	string text,part;
	while (getline(cin, text)) {
		int check = 0;
		for (int i = 0; i < text.size(); i++) {
			text[i] = tolower(text[i]);
		}
		for (int i = 0; i <= (int) text.size() - 7; i++) {
			part = text.substr(i, 7);
			if (part == "problem") {
				check = 1;
				break;
			}
		}
		if (check) {
			cout << "yes\n";
		}
		if (check==0) {
			cout << "no\n";
		}
	}
}