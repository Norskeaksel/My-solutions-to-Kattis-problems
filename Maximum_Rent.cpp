#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long a, b, m, o, case1=0, case2 = 0, case3 = 0;
	cin >> a >> b >> m >> o;
	if ((o - m)>=1) case1 = a * (o - m) + b * (2 * m - o);
	if (2 * (m - 1) + 1 >= o) case2 = (m - 1)*a + b;	
	if ((m - 1)+2 >= o) case3 = (m - 1)*b + a;
	cout << max(max(case1, case2), case3) << endl;
}