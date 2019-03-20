#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n,d;
	cin >> n;
	vector<pair<int, int>>junkDay;
	pair<int, int>j;
	for (int i = 0; i < n; i++) {
		cin >> d;
		j.first = d;
		j.second = i;
		junkDay.push_back(j);
	}
	sort(junkDay.begin(), junkDay.end());
	cout << junkDay[0].second << endl;
}