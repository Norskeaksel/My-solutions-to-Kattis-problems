#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int alwaysu=0, alwaysd=0, asfound=0;
	if(str[0] == 'D'&&str[1] == 'U') alwaysd+=2;
	if (str[0] == 'D') alwaysu++;
	if (str[0] == 'U'&&str[1] == 'D') alwaysu += 2;
	if (str[0] == 'U')alwaysd++;
	for (int i = 2; i < str.size(); i++) {
		if (str[i] == 'D')alwaysu += 2;
		if (str[i] == 'U')alwaysd += 2;
	}
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) asfound++;
	}
	cout<<alwaysu<<endl<<alwaysd<<endl<<asfound<<endl;
}