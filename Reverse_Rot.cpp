#include <iostream>
#include <string>
using namespace std;
int main(){
	int n=1;
	while (1) {
		cin >> n;
		if (n == 0) exit(0);
		string str, rstr;
		cin >> str;
		rstr = str;
		int j = 0;
		for (int i = str.size() - 1; i >= 0; i--) {
			rstr[j] = str[i];
			j++;
		}
		for (int q = 0; q < n; q++) {
			for (int i = 0; i < rstr.size(); i++) {
				if (rstr[i] == 90)
					rstr[i] = 95;
				else if (rstr[i] == 95)
					rstr[i] = 46;
				else if (rstr[i] == 46)
					rstr[i] = 65;
				else
					rstr[i] += 1;
			}
		}
		cout << rstr << endl;
	}
}