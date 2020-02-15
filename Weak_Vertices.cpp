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

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	while (cin >> n) {
		if (n == -1)
			exit(0);
		set<int> ans;
		int graphs[22][22];
		vector<int> neigbours[22];
		fori(n) {
			forj(n) {
				int a;
				cin >> a;
				graphs[j][i] = a;
			}
		}
		fori(n) {
			forj(n) {//j=first neighbour
				if (graphs[j][i] == 1) {
					for (int k = j + 1; k < n; k++) {//k=2. neighbour
						if (graphs[k][i] == 1) {
							if (graphs[k][j] == 1) {
								ans.insert(i);
							}
						}
					}
				}
			}
		}
		fori(n) {
			if (ans.count(i) == 0) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
}