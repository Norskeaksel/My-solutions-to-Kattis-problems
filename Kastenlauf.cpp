#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;
#define x first
#define y second
void dfs(vector<int> &done, vector<vector<int>>&neighbors,int index) {//Trenger & for å endre input
	done[index] = 1;//vi er ferdig med nåværende node
	for (int i : neighbors[index])//for alle naboer til nåværedne node
		if(done[i]==0)//dersom vi ikke er ferdige med dem
			dfs(done, neighbors, i);//
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n += 2;
		pair<double, double>node;
		vector<pair<double, double>>allnodes;
		int xkoord, ykoord;
		for (int i = 0; i < n; i++) {
			cin >> xkoord >> ykoord;
			node.x = xkoord;
			node.y = ykoord;
			allnodes.push_back(node);
		}
		vector<vector<int>>neighbors(n);//neighbors[i] er en vektor med alle naboer til noden med index i
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (abs(allnodes[j].x - allnodes[i].x) + abs(allnodes[j].y - allnodes[i].y) <= 1000)
					neighbors[i].push_back(j);
			}
		}
		for (int i = 0; i < neighbors.size(); i++) {
			//cout << i<<" har disse naboene: ";
			for (int j = 0; j < neighbors[i].size(); j++) {
				//cout << neighbors[i][j] << " ";
			}
			//cout << endl;
		}
		vector<int> done(n,0);
		dfs(done, neighbors, 0);
		if (done[n - 1] == 1)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}