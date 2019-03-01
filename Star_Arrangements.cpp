#include<iostream>	
using namespace std;
int main() {
	int s;
	cin >> s;
	cout << s << ":\n";
	int row1 = 1, row2 = 1;
	while (row1 + row2 <= s) {
		row1++;
		if (s % (row1 + row2) == 0 || s % (row1 + row2) == row1)
			cout << row1 << "," << row2 << endl;
		row2++;
		if(s%row2==0)
			cout << row1 << "," << row2 << endl;
	}
}