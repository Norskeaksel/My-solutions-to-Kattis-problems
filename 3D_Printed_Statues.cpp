#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int printer = 1, statue = 0, counter = 0;
	while (printer < n / 2) {
		printer *= 2;
		counter++;
	}
	statue = (printer - n / 2);
	printer = n / 2;
	while (statue<n)
	{
		statue += printer;
		counter++;
	}
	if (counter == 0)cout << 1<<endl;
	else cout << counter << endl;
}