#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	int t, n,s;
	cin >> t;

	while (t--) {
		set<string> byer;
		string by;
		cin >> n;
		while (n--){
			cin >> by;
			byer.insert(by);
		}
		cout << byer.size()<<endl;
	}
}