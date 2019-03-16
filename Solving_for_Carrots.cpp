#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	int n,p;
	string input = "";
	cin >> n >> p;
		for (int i = 0; i < n+1; i++) {
			getline(cin, input);
		}
		cout<<p;
}