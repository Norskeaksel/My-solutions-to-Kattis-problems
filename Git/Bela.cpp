#include <iostream>
#include <string>
using namespace std;
int main() {
	int h;
	char dom;
	cin >> h >> dom;
	string str;
	int score = 0;
	for (int i = 0; i < 4 * h; i++) {
		cin >> str;
		if (str[0] == 'A') score += 11;
		if (str[0] == 'K') score += 4;
		if (str[0] == 'Q') score += 3;
		if (str[0] == 'J' &&str[1]==dom) score += 20;
		else if (str[0] == 'J') score += 2;
		if (str[0] == 'T') score += 10;

		if (str[0] == '9'&&str[1]==dom) score += 14;
	}
	cout << score<<endl;
}