#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	int t;
	cin >> t;
	string uni, name;
	set<string>winners;
	int counter = 0;
	while (t--&&counter<12) {
		cin >> uni >> name;
		if (!winners.count(uni)) {
			winners.insert(uni);
			cout << uni << " " << name<<endl;
			counter++;
		}
	}
}