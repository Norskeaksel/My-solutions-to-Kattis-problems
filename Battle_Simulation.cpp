#include<iostream>
#include<string>
using namespace std;
int checkCombo(string str,int start) {
		if (str[start-2] != str[start-1] && str[start-2] != str[start] && str[start-1] != str[start])
			return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	string monster;
	cin >> monster;
	//monster += "00000";
	if (monster.size() < 3) {
		for (int i = 0; i < monster.size(); i++) {
			if (monster[i] == 'R')
				cout << 'S';
			if (monster[i] == 'B')
				cout << 'K';
			if (monster[i] == 'L')
				cout << 'H';
		}
	}
	int start = 2;
	int last = 0;
	while (start< monster.size()){
		if (checkCombo(monster, start) == 0) {
			if (monster[start-2] == 'R')
				cout << 'S';
			if (monster[start-2] == 'B')
				cout << 'K';
			if (monster[start-2] == 'L')
				cout << 'H';
			start++;
			last = 0;
		}
		if (checkCombo(monster,start) == 1) {
			cout << 'C';
			start +=3;
			last = 1;
		}
	}
	string copy = monster;
	copy += "000";
	if (last) {
		for (int i = monster.size(); i < start; i++) {
			if (copy[i - 2] == 'R')
				cout << 'S';
			if (copy[i- 2] == 'B')
				cout << 'K';
			if (copy[i- 2] == 'L')
				cout << 'H';
		}
	}
}