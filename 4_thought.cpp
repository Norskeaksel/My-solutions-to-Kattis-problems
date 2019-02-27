#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
	

	}/*int n,svar=0;
		bool ny = false;
		cin >> n;
		vector<int> ledd {4, 4, 4, 4};
		string str = "4";
		int x = 4;
		for (int i = 1; i < x; i++) {
				if ((svar + ledd[i] * 4) < n) {
					ledd[i] *= 4;
					str += " * 4";
					ledd.erase(ledd.begin() + ledd.size());
					i--;
					x--;
				}
				else if (svar + ledd[i] / 4 > n) {
					ledd[i] /= 4;
					str += " / 4";
					ledd.erase(ledd.begin() + ledd.size());
					i--;
					x--;
				}
			svar = 0;
			for (int j = 0; j < i; j++) {
				svar += ledd[j];
			}
			if (svar + 4 <= n) {
				ledd[i] = 4;
				str += " + 4";
			}
			else if (svar + 1 <= n && i < x - 1) {
				str += " + 4 / 4";
				ledd[i] = 1;
				ledd.pop_back();
				x--;
			}
			else if (svar - 4 >= n) {
				ledd[i] = -4;
				str += " - 4";
			}
			else if (svar - 1 >= n && i < x - 1) {
				str += " - 4 / 4";
				ledd[i] == -1;
				ledd.pop_back();
				x--;
			}
			else if (svar == n && i == 2) {
				cout << str + " + 4 - 4 = " << n << endl;
				break;
			}
		}
		svar=0;
		for (int j = 0; j < ledd.size(); j++) {
			svar += ledd[j];
		}
		if (svar == n)
			cout << str + " = " << n << endl;
		if (svar != n)
			cout << "no solution\n";
	}
}*/