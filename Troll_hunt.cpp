#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << ceil(--a / floor((b / c))) << endl;
}
