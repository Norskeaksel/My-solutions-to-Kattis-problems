#include <iostream>
#include<string>
using namespace std;
int main() {
	string str;
	int d;
	cin >> str >> d;
	if ((str == "OCT" && d == 31) || (str == "DEC"&&d == 25))
		cout << "yep\n";
	else
		cout << "nope\n";
}