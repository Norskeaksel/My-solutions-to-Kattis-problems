#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
using namespace std;
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define all(v) (v).begin(),(v).end()
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

bool commonNeigbours(int base, vector<set<int>> neighbors) {
	bool ans = 0;
	for (auto n : neighbors[base]) {//gå gjennom settet som alle naboene til basen
		//cout << "base: " << base << endl;
		for (auto n2 : neighbors[n])//fiks dette
			if (n2 == n)//if 2 the bases neighbors is connected the its not a weak vertice
				return true;
		return false;
	}
}

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	while (cin >> n) {
		if (n == -1)
			exit(0);
		int graphs[22][22];
		vector<set<int>> neighbors;
		set<int> empty;
		fori(n) {
			neighbors.push_back(empty);
			forj(n) {
				int a;
				cin >> a;
				graphs[j][i] = a;
				neighbors[i].insert(i);
			}
		}
		vector<int>ans;
		fori(n) {
			if (commonNeigbours(i, neighbors) == false)
				ans.push_back(i);
		}
		sort(all(ans));
		fori(ans.size()){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}