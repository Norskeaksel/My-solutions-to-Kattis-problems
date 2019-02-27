#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string h;
	string hand[5];
	for (int i = 0; i < 5; i++) {
		cin >> h;
		hand[i] = h;
	}
	int svar[5] = {};
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			if (hand[j][0] == hand[i][0])
				svar[i]++;
		}
	}
	int* p = max_element(svar, svar + 5);
	cout << *p << endl;
}