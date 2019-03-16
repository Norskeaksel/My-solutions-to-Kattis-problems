#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int a = 0; a < n; a++) {
		char bok[26];
		int check = 0;
		for (int i = 0; i < 26; i++) {
			bok[i] = 'a' + i;
		}
		string str;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			str[i] = tolower(str[i]);
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < str.size(); j++) {
				if (str[j] == bok[i])
					bok[i] = 'A';
			}
		}	
		for (int i = 0; i < 26; i++) {
			if (bok[i] != 'A'&&check == 0) {
				cout << "missing ";
				check = 1;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (bok[i] != 'A')
				cout << bok[i];
		}
		if (check == 0)
			cout << "pangram";
		cout << endl;
	}
}