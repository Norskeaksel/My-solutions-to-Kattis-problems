#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
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

vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	string line;
	map<string, int>s2i;
	map<int, string>i2s;
	while (getline(cin, line)) {
		vector<string> s = strsplit(line);
		if (s[0] == "clear") {
			s2i.clear();
			i2s.clear();
		}
		else if (s[0] == "def") {
			int num = stoi(s[2]);
			if(s2i.count(s[1])){
				i2s.erase(s2i[s[1]]);
			}
			s2i[s[1]] = num;
			i2s[num] = s[1];
		}
		else if (s[0] == "calc") {
			string ans;
			int num = 0;
			for (int i = 1; i < s.size(); i += 2) {
				if (s2i.count(s[i])) {
					int a = s2i[s[i]];
					if (s[i - 1] == "-")
						num -= a;
					else
						num += a;
				}
				else {
					ans = "unknown";
					break;
				}
			}
			if (i2s[num] != "" && ans != "unknown")
				ans = i2s[num];
			else
				ans = "unknown";
			forx(s.size() - 1)
				cout << s[x] << " ";
			cout << ans << endl;
		}
	}
}