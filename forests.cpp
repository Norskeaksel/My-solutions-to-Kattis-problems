#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> peoplesTrees[123];
int main() {
	int totP, totT;
	cin >> totP >> totT;
	int p, t;
	while (cin >> p >> t) {
		peoplesTrees[p].push_back(t);
	}
	for (int i = 1; i <= totP; i++) {
		sort(peoplesTrees[i].begin(), peoplesTrees[i].end());
	}
	set<vector<int>>pairs;
	int svar = 0;
	for (int i = 1; i <= totP; i++) {
		if (pairs.count(peoplesTrees[i]) == 0) {
			svar++;
			pairs.insert(peoplesTrees[i]);
		}
	}
	cout << svar << endl;
}
