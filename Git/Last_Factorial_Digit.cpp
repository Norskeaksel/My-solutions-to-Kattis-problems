#include<iostream>
#include<string>
#include <sstream>
using namespace std;
inline int Factorial(int x) {
	return (x == 1 ? x : x * Factorial(x - 1));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		int svar=Factorial(num);
		ostringstream convert;
		convert << svar;
		string str = convert.str();
		cout << str[str.size() - 1]<<endl;
	}
}