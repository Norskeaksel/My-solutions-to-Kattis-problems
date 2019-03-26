#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	set<string> words, compound;
	string a, b;
	while (cin>>a){
		cin >> b;
		words.insert(a);
		words.insert(b);
	}
	for (auto i : words) {
		for (auto j : words) {
			if (j !=i) {
				compound.insert(i + j);
				compound.insert(j + i);
			}
		}
	}
	for (auto i : compound) {
		cout << i << endl;
	}
}