#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double B, Br, Bs, A, As,Ar, Bpenger, Apenger;
	cin >> B >> Br >> Bs >> A >> As;
	Bpenger = (Br - B)*Bs;
	Ar = (Br - B)*Bs / As + A;
	Apenger = (Ar - A)*As;
	Ar++;
	cout << floor(Ar)<<endl;
}