#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
ofstream write("ans1.txt", ios::app);
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
#define trav(v) for(auto &i:v)

string xToBinary(vector<string>&x, int digits) {
	string str;
	fori(digits)
		str += "2";
	fori(x.size()) {
		char c = x[i][0];
		if (c == 'v')
			continue;
		int sz = x[i].size();
		int nr;
		if (c == '~') {
			if (sz == 3)
				nr = x[i][2] - '1';
			else {
				if (x[i][2] == '1'&&x[i][3] == '0')
					nr = 9;
				else if (x[i][2] == '2'&&x[i][3] == '0')
					nr = 19;
				else
					nr = (x[i][3] - '1') + 10;
			}
			if (str[nr] == '1')
				str[nr] = '3';
			else if(str[nr]!='3')
				str[nr] = '0';
		}
		else {
			if (sz == 2)
				nr = x[i][1] - '1';
			else {
				if (x[i][1] == '1'&&x[i][2] == '0')
					nr = 9;
				else if (x[i][1] == '2'&&x[i][2] == '0')
					nr = 19;
				else
					nr = (x[i][2] - '1') + 10;
			}
			if (str[nr] == '0')
				str[nr] = '3';
			else if(str[nr]!='3')
				str[nr] = '1';
		}
	}
	return str;
}

pair<int,int> binaryString2Int(string str){
	int a1=0, a2=0;
	fori(str.size()){
		a1 = a1 << 1;
		a2 = a2 << 1;
		if(str[i]=='1'|| str[i] == '3'){
			a1++;
		}
		if (str[i] != '0'&&str[i] != '3')
			a2++;
	}
	return { a1,a2 };
}
vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}

bool viable2(int a1,int a2, int comb,int n){
	int t1 = a1 & comb;
	int t2 = ((1 << n)- 1)- (a2 | comb);
	if (t1)
		return 1;
	if (t2)
		return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cin.ignore();
		vector<pair<int,int>>clause2;
		forj(m) {
			string str;
			getline(cin, str);
			vector<string>clause = strsplit(str);
			string binrep = xToBinary(clause, n);
			clause2.push_back(binaryString2Int(binrep));
		}
		fork(pow(2, n)){
			trav(clause2) {
				if (!viable2(i.first,i.second, k,n)) {
					goto next;
				}
			}
			cout << "satisfiable\n";
			goto theEnd;
		next:;
		}
		cout << "unsatisfiable\n";
	theEnd:;
	}
	return 0;
}