#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double a, n,r,pi;
	cin >> a >> n;
	pi = acos(-1);
	r = sqrt(a / pi);
	if (n>=2*pi*r)
		cout << "Diablo is happy!\n";
	else
		cout << "Need more materials!\n";
}	