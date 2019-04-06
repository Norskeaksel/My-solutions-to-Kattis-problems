#include <iostream>
#include <string>
#include <stack>
using namespace std;
void e(char r, int i) {

}
int main() {
	int n;
	cin >> n;
	cin.ignore();
	string str;
	getline(cin, str);
	stack<char>s;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(' || c == '{' || c == '[')
			s.push(c);
		/*if (s.empty()) */
		if (c == ')' || c == '}' || c == ']') {
			if (s.empty()) {
				cout << str[i] << " " << i;
				exit(0);
			}
			char r = s.top();
			s.pop();
			if (c == ')'&&r != '(' || c == '}'&&r != '{' || c == ']'&&r != '[') {
				cout << str[i] << " " << i;
				exit(0);
			}
		}
	}
	//if(!s.empty())
		//cout << str[n - 1] << " " << n - 1;
	//else
		cout << "ok so far";
}