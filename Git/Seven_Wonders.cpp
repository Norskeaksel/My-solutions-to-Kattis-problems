#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	string cards;
	cin >> cards;

	sort(cards.begin(), cards.end());
	int T=0,C=0,G=0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i] == 'T')T++;
		else if (cards[i] == 'C')C++;
		else if (cards[i] == 'G')G++;
	}
	int svar = T * T + C * C + G * G;
	while (0 < T && 0 < C && 0 < G) {
		svar += 7;
		T--, C--, G--;
	}
	cout << svar << endl;
}