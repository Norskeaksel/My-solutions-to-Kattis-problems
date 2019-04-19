#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define ll long long
#define double long double
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

void findAndReplaceAll(string & data, string toSearch, string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);

	// Repeat till end is reached
	while (pos != string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos = data.find(toSearch, pos + toSearch.size());
	}
}
vector<string> a = { "four", "and", "are", "bea", "bee", "eye", "for", "one", "owe", "sea", "see", "too", "two", "why", "won", "you", "at", "be", "oh", "to", "Four", "And", "Are", "Bea", "Bee", "Eye", "For", "One", "Owe", "Sea", "See", "Too", "Two", "Why", "Won", "You", "At", "Be", "Oh", "To" };
vector<string> b = { "4", "&", "r", "b", "b", "i", "4", "1", "o", "c", "c", "2", "2", "y", "1", "u", "@", "b", "o", "2", "4", "&", "R", "B", "B", "I", "4", "1", "O", "C", "C", "2", "2", "Y", "1", "U", "@", "B", "O", "2" };

int main() {
	map<string, string>dic;
	fori(a.size()) {
		dic[a[i]] = b[i];
	}
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	fori(t) {
		getline(cin, str);
		forj(a.size()) {
			findAndReplaceAll(str, a[j], b[j]);
		}
		cout << str << endl;
	}
}