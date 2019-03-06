#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	{
		double stor = 0, liten = 0, space = 0, symbol = 0;
		string s;
		cin >> s;
		vector<char> v(s.begin(), s.end());//Dette deler om en streng s til individuelle karakterer i en vektror.
		double n = s.size();

			for (int i = 0; i < s.size(); i++) {
				char tegn = s[i]; 
				if (tegn > 64 && tegn < 91) {
					stor++;
				}
				else if (tegn == 95) {
					space++;
				}
				else if (tegn > 96 && tegn < 123) {
					liten++;
				}
				
				
				else
				{
					symbol++;
				}
			}
		
		
		cout << space / n << endl;
		cout << liten / n << endl;
		cout << stor / n << endl;
		cout << symbol / n << endl;
	}
}