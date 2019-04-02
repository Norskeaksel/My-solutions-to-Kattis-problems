#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long c;
		vector<long long>candy;
		for (int i = 0; i < n; i++) {
			cin >> c;
			candy.push_back(c);
		}
		long long works = 0;
		double rest = 0;
		for (int i = 0; i < n; i++) {
			rest += -candy[i] / n;
			works += candy[i] / n;
		}
	}
}

/*while (!cin.eof()){
	cin >> c;
	char c1 = cin.get();
	char c2 = cin.peek();
	candy.push_back(c);
	if (c2 == '\n')
		break;
}*/