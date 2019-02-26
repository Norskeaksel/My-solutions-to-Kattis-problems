#include <iostream>
#include <string>
using namespace std;
char rot(char c,int rotate) {
	int num = c;
	bool check=true;
	while (num + rotate > 90) {
		c = 'A' + (num + rotate) - 91;
		check = false;
	}
	if(check)
		c += rotate;
	return c;
}
void func() {
	string mainstr;
	cin >> mainstr;
	int rotate = 0;
	for (int i = 0; i < mainstr.size()/2; i++) {
		rotate += mainstr[i] - 'A';
	}
	rotate = rotate % 26;
	for (int j = 0; j < mainstr.size() / 2; j++) {
		mainstr[j] =  rot(mainstr[j], rotate);
	}
	rotate = 0;
	for (int i = mainstr.size() / 2; i < mainstr.size(); i++) {
		rotate += mainstr[i] - 'A';
	}
	rotate % 26;
	for (int j = mainstr.size() / 2; j < mainstr.size(); j++) {
		mainstr[j] = rot(mainstr[j], rotate);
	}
	for (int i = 0; i < mainstr.size(); i++)
		cout << mainstr[i];

	for (int i = 0; i < mainstr.size()/2; i++) {
		int r=mainstr[i + mainstr.size() / 2];
		char s = mainstr[i];
		mainstr[i] = rot(s, r-'A');
	}
	for (int i = 0; i < mainstr.size()/2; i++)
		cout << mainstr[i];
}

int main() {
	cout<<rot('A',180);
}