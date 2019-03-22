#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int main() {
	int num;
	while (cin >> num) {
		int currentval = 1;
		if (sqrt(num) == floor(sqrt(num))) {
			currentval+= sqrt(num);
		}
		for (int i = 2; i < sqrt(num); i++) {
			//cout << currentval << " ";
			if (num%i == 0) {
				currentval += i;
				currentval += num / i;
			}
		}
		if (currentval == num) {
			cout << num << " perfect\n";
		}
		else if (currentval == num - 2 || currentval == num - 1 || currentval == num + 1 || currentval == num + 2) {
			cout << num << " almost perfect\n";
		}
		else
			cout << num << " not perfect\n";
	}
}
/*int checkPerfect(int num) {
	int cur = 0;
	set<int> currentval;
	for (int i = 1; i < num; i++) {
		if (num%i == 0) {
			cur += i;
			currentval.insert(cur);
		}
		if (cur == num) {
			cout << num << " perfect\n";
			return 0;
		}
		else {
			for (int j = -2; j <= 2; j++) {
				if (!j)
					j++;
				if (currentval.count(num + j)) {
					cout << num << " almost perfect\n";
					return 0;
				}
			}
		}
	}
	return 1;
}*/