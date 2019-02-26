#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string t,a;
	getline(cin, t);
	istringstream iss(t); //
	string word;
	vector<string> words;

	while (iss >> word) {
		words.push_back(word);// push_back legger til et element på slutten av vektoren words
	}

	for (int i = 0; i < words.size(); ++i) {//words.size() er antall elementer i vektoren words
		for (int j = i+1; j < words.size(); ++j) {
			string word1 = words[i]; //deklarerer word1 til å være ord nummer i i vektoren
			string word2 = words[j];
			if (word1 == word2) {
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;
	return 0;
}