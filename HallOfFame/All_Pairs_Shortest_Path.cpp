//#include<bits/stdc++.h> includerer alt, men fungerer ikke i visual studio
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>//For å jobbe med filer
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <cstdlib>//rand()
#include <ctime> //srand()
#include <iterator>
#include <queue>
#include <stack>
#include <functional>// tillater bruk av greater<int>
#include <stdio.h>// tillater automatisk lesing av testinnput
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define all(v) (v).begin(),(v).end()
#define ll long long
#pragma warning(disable:4996)

int const dim = 151;

void floyd_warshall(long long matrix[dim][dim], int n) {//Dobbeltsjekk denne
	fork(n) {
		fori(n) {
			forj(n) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				if (matrix[i][j] < -1e12) {
					matrix[i][j] = -1e12;
				}
			}
		}
	}
}

long long matrix[dim][dim], cop[dim][dim];
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	int n, e, q;
	while (cin >> n >> e >> q) {
		if (!(n || e || q))
			break;
		fill_n((long long*)matrix, dim* dim, 1e18);
		fori(n) {
			matrix[i][i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			matrix[v][u] = min(matrix[v][u], 1LL * w);//caster w til long
		}

		floyd_warshall(matrix, n);
		fori(n) {
			if (matrix[i][i] < 0)
				matrix[i][i] = -1e6;
		}
		copy_n((ll*)matrix, dim*dim, (ll*)cop);
		floyd_warshall(matrix, n);
		/*fori(n) {
			forj(n) {
				cout << matrix[j][i] << " ";
			}
			cout << endl;
		}*/
		fori(q) {
			int y, x;
			cin >> y >> x;
			if (matrix[x][y] > 1e17 - 2e13)
				cout << "Impossible\n";
			else if (matrix[x][y] != cop[x][y] || matrix[x][y] <= -1e12)
				cout << "-Infinity\n";
			else
				cout << matrix[x][y] << endl;
		}
		cout << endl;
	}
}