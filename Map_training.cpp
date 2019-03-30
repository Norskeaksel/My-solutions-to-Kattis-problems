#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
	map<char,string> mymap;
	mymap['a']="@";
	mymap['b'] = "8";
	mymap['c'] = "(";
	mymap['d'] = "|)";
	mymap['e'] = "3";
	mymap['f'] = "#";
	mymap['g'] = "6";
	mymap['h'] = "[-]";
	mymap['i'] = "|";
	mymap['j'] = "_|";
	mymap['k'] = "|<";
	mymap['l'] = "1";
	mymap['m'] = "[]\\/[]";
	mymap['n'] = "[]\\[]";
	mymap['o'] = "0";
	mymap['p'] = "|D";
	mymap['q'] = "(,)";
	mymap['r'] = "|Z";
	mymap['s'] = "$";
	mymap['t'] = "']['";
	mymap['u'] = "|_|";
	mymap['v'] = "\\/";
	mymap['w'] = "\\/\\/";
	mymap['x'] = "}{";
	mymap['y'] = "`/";
	mymap['z'] = "2";
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size();i++) {
		str[i] = tolower(str[i]);
		if (str[i]<'a' || str[i]>'z') cout << str[i];
		else {
			cout << mymap[str[i]];
		}
	}
	cout << endl;
}