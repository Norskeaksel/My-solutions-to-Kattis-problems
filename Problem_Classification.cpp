#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
#define in(t) int t; cin >> t; while(t--)

vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	map<string, set<string>>assosiated;
	map<string, int>nr;
	in(t){
		string category;
		int n;
		cin >> category >> n;
		nr[category] = 0;
		fori(n){
			string a;
			cin >> a;
			assosiated[a].insert(category );
		}
	}
	string line;
	while(getline(cin,line)){
		vector<string>word = strsplit(line);
		for(auto w:word){
			if(assosiated.count(w)){
				for (auto &j : assosiated[w]){
					nr[j]++;
				}
			}
		}
	}
	int m = 0;
	for (auto i : nr)
		m = max(m, i.dy);
	vector<string>ans;
	for (auto i : nr) {
		if (i.dy == m)
			ans.push_back(i.dx);
	}
	sort(all(ans));
	for (auto i : ans) cout << i << endl;
}