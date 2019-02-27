#include<iostream>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int garmy[100000] = {}, marmy[100000] = {};
		int ng, nm;
		cin >> ng >> nm;
		for (int i = 0; i < ng; i++) {
			int sol;
			cin >> sol;
			garmy[i] = sol;
		}
		for (int i = 0; i < nm; i++) {
			int sol;
			cin >> sol;
			marmy[i] = sol;
		}
		int Gwin=*max_element(garmy, garmy+100000);
		int Mwin = *max_element(marmy, marmy + 100000);
		if (Gwin >= Mwin)
			cout << "Godzilla\n";
		else
			cout << "MechaGodzilla\n";
	}
}