#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	int obnr, seen;
	cin >> obnr >> seen;
	set<int>seenob;
	int o;
	for (int i = 0; i < seen; i++) {
		cin >> o;
		seenob.insert(o);
	}
	for (int i = 0; i < obnr; i++) {
		if (!seenob.count(i))
			cout << i << endl;
	}
	cout << "Mario got " << seenob.size() << " of the dangerous obstacles.\n";
}