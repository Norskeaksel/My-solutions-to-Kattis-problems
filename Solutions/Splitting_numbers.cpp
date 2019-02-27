#include <iostream>
using namespace std;
int SumAvSiffer(int tall){
	int temp,svar=0;
	while(tall !=0){
		temp = tall % 10;
		svar += temp;
		tall = (tall - temp) / 10;
	}
	return svar;
}
int main() {
	int l, suml = 0, d, sumd = 0, x, sumAvlSiffer = 0, n = 0, m = 0;
	cin >> l >> d >> x;
	while (suml != x) {
		suml = SumAvSiffer(l);
		l++;
	}
	while (sumd != x) {
		sumd = SumAvSiffer(d);
		d--;
}
	cout << l-1 << endl << d+1 << endl;
}