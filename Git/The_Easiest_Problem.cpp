#include <iostream>
using namespace std;
int SumAvSiffer(int tall) {
		int temp, svar = 0;
		while (tall != 0) {
			temp = tall % 10;
			svar += temp;
			tall = (tall - temp) / 10;
		}
		return svar;
}
int main() {
	int n=1,i=11,a,b;
	while (n != 0) {
		cin >> n;
		while (n != 0) {
			a = SumAvSiffer(n);
			b = SumAvSiffer(i*n);
			if (a == b) {
				cout << i << endl;
				i = 11;
				break;
			}
			i++;
		}
	}
}