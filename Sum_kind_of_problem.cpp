#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k,t;
		cin >> t>>k;
		cout << t << " "<<k*(k+1)/2<<" "<<k*k<<" "<<k*k+k<<endl;
	}
}