#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
		;
	while (t--) {
		string l;
		getline(cin, l);
		istringstream iss(l);
		string word;
		vector<string> words;
		while (iss >> word)
			words.push_back(word);
		while (1) {
			string animal, goes, sound;
			cin >> animal >> goes >> sound;
			words.erase(remove(words.begin(), words.end(), sound), words.end());
			if (animal == "what"&&goes == "does"&&sound == "the") break;
		}
		for (int i = 0; i < words.size(); i++) {
			cout << words[i] << " ";
		}
		cout << endl;
		getline(cin,l );
	}
}