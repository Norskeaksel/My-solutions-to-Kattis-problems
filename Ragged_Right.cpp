#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string arr[123];
int num[123] = {};
int main() {
	string str;
	int i = 0;
	while (getline(cin, str)) {
		arr[i] = str;
		num[i] = str.size();
		i++;
	}
	int stor=*max_element(num, num + 111);
	int svar = 0;
	for (int j = 0; j < i - 1; j++) {
		svar += (stor - num[j])*(stor - num[j]);
	}
	cout << svar << endl;
}