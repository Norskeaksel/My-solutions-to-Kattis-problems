#include <iostream>
#include<vector>
using namespace std;
struct Edge {
	int til;
	int lengde;
	int fra;
};
struct Vertex {
	vector<Edge>kanter;
	int avstand = 1e9;
};
bool operator<(Edge e1, Edge e2) {
	if (e2.lengde < e1.lengde)
		return true;
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, c;
		cin >> m >> c;
		for (int i = 0; i < (c*(c - 1) / 2); i++) {

		}
	}
}