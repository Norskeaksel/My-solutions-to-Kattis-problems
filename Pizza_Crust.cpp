#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double R, C;	
	cin >> R >> C;
	cout<<setprecision (14) << pow(R - C, 2) / pow(R, 2)*100 << endl;
}