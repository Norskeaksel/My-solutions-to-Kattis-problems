#include <iostream>
using namespace std;
int main() {
	double a1, b1, a2, b2, svar1 = 0, svar2 = 0, i, j, k, l;
	cin >> a1 >> b1 >> a2 >> b2;
	svar1 = (b1 * (b1 + 1) / 2 - (a1*(a1 - 1)) / 2)/(b1-a1+1);
	svar1+= (b2 * (b2 + 1) / 2 - (a2*(a2 - 1)) / 2) / (b2 - a2 + 1);
	cin >> a1 >> b1 >> a2 >> b2;
	svar2 = (b1 * (b1 + 1) / 2 - (a1*(a1 - 1)) / 2) /(b1 - a1 + 1);
	svar2+= (b2 * (b2 + 1) / 2 - (a2*(a2 - 1)) / 2) / (b2 - a2 + 1);
	if (svar1 < svar2) cout << "Emma\n";
	else if (svar2 < svar1) cout << "Gunnar\n";
	else cout << "Tie\n";
	/*for (i = a1; i <= b1; i++) {
		svar1 += i;
	}
	for (j = a2; j < b2; j++) {
		svar1 += j;
	}
	svar1 = svar1 / (i - a1 + j - a2);
	cin >> a1 >> b1 >> a2 >> b2;
	for (i = a1; i <= b1; i++) {
		svar2 += i;
	}
	for (j = a2; j < b2; j++) {
		svar2 += j;
	}
	svar2 = svar2 / (i - a1 + j - a2);
*/
}