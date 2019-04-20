//#include<bits/stdc++.h> includerer alt, men fungerer ikke i visual studio
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>//For å jobbe med filer
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <cstdlib>//rand()
#include <ctime> //srand()
#include <iterator>
#include <queue>
#include <stack>
#include <functional>// tillater bruk av greater<int>
#include <stdio.h>// tillater automatisk lesing av testinnput
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define all(v) (v).begin(),(v).end()
#define ll long long
#pragma warning(disable:4996)
pair<char, char> oldGrid[1234][1234],newGrid[1234][1234];
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	int y, x;
	while (cin >> y >> x) {
		if (!y && !x)
			exit(0);
		pair<char, char> b;
		char a;
		fori(y) {
			forj(x) {
				cin >> a;
				b = {tolower(a),a};
				oldGrid[j][i] = b;
			}
		}
		vector<pair<string,string>> strings;
		forj(x) {
			pair<string,string> str;
			fori(y) {
				str.first += oldGrid[j][i].first;
				str.second += oldGrid[j][i].second;
			}
			strings.push_back(str);
		}
		sort(all(strings));
		//for (auto i : strings) { cout << i.second << " "; }
		//cout << endl;
		fori(y) {
			string svar;
			forj(x) {
				svar += strings[j].second[i];
			}
			cout << svar << endl;
		}
		cout << endl;
	}
}
/*forj(y) {
	fori(x) {
		newGrid[i][j] = strings[j][i];
	}
}
vector<string>cmon;
forj(y) {
	string svar;
	fori(x) {
		svar+=newGrid[j][i];
	}
	cmon.push_back(svar);
	//reverse(all(svar));
	for (int k = svar.size() - 1; k >= 0; k--)cout << svar[k];
	cout << endl;
}*/