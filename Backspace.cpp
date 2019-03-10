#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	vector<char>vec;
	int c = 0;
	for (int j = str.size() - 1; j >= 0; j--) {
		if (str[j] == '<')
			c++;
		else {
			if (!c)
				vec.push_back(str[j]);
			else 
				c--;
		}
	}
	for (int i = vec.size()-1;i>=0; i--)
		cout << vec[i];
}
/*for (int i = 0; i < str.size(); i++) {
if (str[i] == '<') {
int j = i;
int c=0;
while(str[j]=='<'){
j++;
c++;
}
str.erase(str.begin() + i - c, str.begin() + i+c);
i -= c;
}
}*/