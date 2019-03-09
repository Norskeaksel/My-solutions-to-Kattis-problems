#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string>DOMjudge, Kattis;
	set<string> DOM, Katt,all;
	string str;
	map<string, int>K, D;
	for (int i = 0; i < n; i++) {
		cin >> str;
		D[str]++;
		//cout << D[str] << endl;
		//DOMjudge.push_back(str);
		//DOM.insert(str);
		all.insert(str);
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		K[str]++;
		//Kattis.push_back(str);
		//Katt.insert(str);
		all.insert(str);
	}
	/*for (auto j : DOM) {
		for (int i = 0; i < n; i++) {
			if (DOMjudge[i] == j){
				D[j]++;
			}
		}
	}*/
	/*for (auto j : Katt) {
		for (int i = 0; i < n; i++) {
			if (Kattis[i] == j) {
				K[j]++;
			}
		}
	}*/
	int svar = 0;
	for (auto i : all) {
		//cout << i << " " << K[i] << " " << D[i] << endl;
		svar += min(K[i], D[i]);
	}
	cout << svar<<endl;
}