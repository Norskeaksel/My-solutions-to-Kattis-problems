#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double c, l, w, b, svar = 0;
	cin >> c >> l;
	for (int i = 0; i < l; i++) {
		cin >> w >> b;
		svar += c*w*b*1.0;
	}
	cout <<fixed<< setprecision(7)<< svar << endl;
}