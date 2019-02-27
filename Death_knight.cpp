#include <iostream>
#include <string>
using namespace std;
int main() {
	int svar, n, i, j;
	string ODC;
	cin >> n;
	svar = 0;
	for (i = 0; i < n; i++) {
		cin >> ODC;
		svar++;
		for (j = 0; j < ODC.length(); j++) {
			if(ODC[j] == 'C'&&ODC[j + 1] == 'D'){
				svar--;
				break;
			}
		}
	}
	cout << svar << endl;
}