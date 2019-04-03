#include <iostream>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		cout << a/b <<" "<< a % b << " / " << b<<endl;
		cin >> a >> b;
	}
}