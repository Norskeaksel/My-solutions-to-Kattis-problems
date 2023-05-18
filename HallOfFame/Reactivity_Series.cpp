#include<iostream>
#include<vector>
#include<algorithm>
#include <utility>
using namespace std;
vector<int>node[12345] = {};
int done[12345] = {};
vector<int>topo;
void dfs(int current) {
	if (done[current]++);
	else {
		for (auto e : node[current]) {
			if (done[e] == 0)
				dfs(e);
		}
		topo.push_back(current);
	}
}

int main() {
	int metal[1234] = {};
	int nr, obs;
	vector<int>svar;
	cin >> nr >> obs;
	for (int i = 0; i < nr; i++) {
		svar.push_back(i);
	}
	int big, small;
	vector<int>bigvec;
	vector<int>smallvec;
	for (int i = 0; i < obs; i++) {
		cin >> big >> small;
		node[big].push_back(small);
		//bigvec.push_back(big);
		//smallvec.push_back(small);
		//metal[small] = max(metal[small], metal[big] + 1);
		//for (int j = 0; j < obs; j++) {cout << metal[j] << " ";}cout << endl;
	}
	for (int i = 0; i < nr; i++) {
		dfs(i);
	}
	reverse(topo.begin(), topo.end());
	int good = 1;
	for (int i = 0; i < topo.size()-1; i++) {
		int isedge = 0;
		for (int j = 0; j < node[topo[i]].size(); j++) {
			if (node[topo[i]][j] == topo[i+1])
				isedge = 1;
		}
		if (!isedge)
			good = 0;
	}
	if (good)
		for (int i = 0; i < topo.size(); i++)
			cout << topo[i] << " ";
	else {
		cout << "back to the lab\n";
	}
}