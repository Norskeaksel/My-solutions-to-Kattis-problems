#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int lives = 10;
	string word, guess;
	cin >> word >> guess;
	set<char> contain;
	for (auto i : word)
		contain.insert(i);
	for (auto i : guess){
		if(contain.count(i)){
			contain.erase(i);
			if (contain.empty()) {
				cout << "WIN\n";
				exit(0);
			}
		}
		else{
			lives--;
			if(!lives){
				cout << "LOSE\n";
				exit(0);
			}
		}
	}
}