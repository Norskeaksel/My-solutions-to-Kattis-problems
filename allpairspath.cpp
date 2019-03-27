#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int const dim = 151;
#define fori(n) for (int i = 0; i < (n); i++)
#define forj(n) for (int j = 0; j < (n); j++)
#define fork(n) for (int k = 0; k < (n); k++)
void floyd_warshall(long long matrix[dim][dim], int n) {//Dobbeltsjekk denne
	fork(n) {
		fori(n) {
			forj(n) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
}

long long matrix[dim][dim],cop[dim][dim];
int main() {
	int n, e, q;
	while (cin >> n >> e >> q) {
		if (!(n || e || q))
			break;
		fill_n((long long*)matrix, dim* dim, 1e17);
		for (int i = 0; i < e; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			matrix[v][u] = min(matrix[v][u], 1LL*w);//caster w til long
		}
		fori(n) {
			matrix[i][i] = 0;
		}
		
		floyd_warshall(matrix, n);
		fori(n) {
			if (matrix[i][i] < 0)
				matrix[i][i]=-1e6;
		}
		copy_n((int*)matrix, dim*dim, (int*)cop);
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
			if (matrix[x][y] > 1e17-2e8)
				cout << "Impossible\n";
			else if (matrix[x][y] != cop[x][y])
				cout << "-Infinity\n";
			else
				cout << matrix[x][y] << endl;
		}
		cout << endl;
	}
}