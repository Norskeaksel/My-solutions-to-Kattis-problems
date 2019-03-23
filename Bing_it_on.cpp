#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N,svar=0;
	string str;
	map <string,int> strvec;
	cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			cout << strvec[str] << endl;//Printer hvor mange str vi har sett

			int strlength = str.length();//finner lengden til stringen jeg setter inn
			for (int j = 1; j <= strlength; j++) {
				strvec[str.substr(0, j)]++;//setter inn en hau med ord i mapet
			}
		}
}