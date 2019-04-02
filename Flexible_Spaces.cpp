#include <iostream>
#include <set>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
	int w, p;
	cin >> w >> p;
	int in;
	vector<int>walls;
	set<int>posibilities;
	for (int i = 0; i < p; i++) {
		cin >> in;
		walls.push_back(in);
	}
	posibilities.insert(w);
	for (int i = 0; i < walls.size(); i++) {
		posibilities.insert(walls[i]);
		posibilities.insert(w - walls[i]);
		for (int j = i+1; j < walls.size(); j++) {
			posibilities.insert(walls[j] - walls[i]);
		}
	}
	for (auto i : posibilities)
		cout << i << " ";
}