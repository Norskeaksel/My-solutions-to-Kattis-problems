#include<iostream>
#include <iomanip> 
using namespace std;
int main() {
	int n;
	cin >> n;
	double anslag=0, tid=0,a,t;

	while (n--) {
		cin >> a>> t;
		anslag += a;
		tid += t;
	}
	double svar=tid/(60*anslag);
	if (svar <= 1)
		cout << "measurement error\n";
	else 
		cout << setprecision(14) << svar << endl;
}