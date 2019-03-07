#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double X, Y;
	cin >> X >> Y;
	if (-X / (Y - 1) < -100 || -X / (Y - 1) > 100) cout << "IMPOSSIBLE\n";
	else if (Y == 1 && X == 0) cout << "ALL GOOD\n";
	else cout << setprecision(14) <<-X/(Y-1)<< endl;
}