#include <iostream>
#include<string>
using namespace std;
int main() {
	int limit, n,out=0,move,svar=0;
	cin >> limit >> n;
	string str;
	while (n--) {
		cin >> str>>move;
		if (str == "enter") {
			if (out + move > limit)
				svar++;
			else
				out += move;
		}
		if (str == "leave")
			out -= move;
	}
	cout << svar << endl;
}