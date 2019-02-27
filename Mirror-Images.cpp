#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	int t, r, c;
	cin >> t >> c >> r;
	string dot;
	for (int a = 1; a < t+1; a++) {
		cout << "Test " << a << endl;
		for (int i = 1; i < c + 1; i++) {
			for (int j = 1; j < r + 1; j++) {
				 cin >> dot;
				 cout << dot;
				
			}
			cout << endl;
		}
	}
}