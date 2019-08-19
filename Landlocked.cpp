#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
#define in(t) int t; cin >> t; while(t--)

struct Spot {
	int x;
	int y;
	int d;
	char n;
};
Spot grid[1234][1234];
Spot backup[1234][1234];
map<char, int>m;
int height, width;
priority_queue<Spot>pq;
bool operator<(Spot a, Spot b) {
	return a.d > b.d;
}
void printGraph() {
	fory(height) {
		forx(width)
			cout << grid[x][y].n;
		cout << endl;
	}
	cout << endl;
}
void revertGrid() {
	fory(height) {
		forx(width) {
			Spot &g = grid[x][y];
			Spot b = backup[x][y];
			if (b.n == 'W'&&g.d == 0);
			else
				g.n=b.n;
		}
	}
}

void dijkstra() {
	while (!pq.empty()) {
		Spot c = pq.top();
		pq.pop();
		grid[c.x][c.y].n = 'd';
		if (c.n != 'W')
			m[c.n] = min(m[c.n], c.d);
		for (int i = 0; i < 8; i++) {
			int x = c.x + (i == 0) - (i == 1) - (i == 4) - (i == 5) + (i == 6) + (i == 7);
			int y = c.y + (i == 2) - (i == 3) - (i == 4) + (i == 5) - (i == 6) + (i == 7);
			Spot &p = grid[x][y];
			if (p.n == 'x' || p.n == 'd');
			else if (p.n == c.n) {
				p.d = c.d;
				pq.push(p);
			}
			/*else if (p.n == 'W') {
				revertGrid();
				dijkstra(p);
			}*/
			else if (p.d > c.d + 1) {
				p.d = c.d + 1;
				pq.push(p);
			}
		}
		//printGraph();
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	fill_n((char*)grid, 1234 * 1234, 'x');
	cin >> height >> width;
	int check = 1;
	Spot start;
	fory(height) {
		forx(width) {
			char a;
			cin >> a;
			m[a] = 3456;
			grid[x][y] = { x,y,3456,a };
			if (a == 'W') {
				pq.push({ x,y,0,a });
			}
		}
	}
	copy_n((Spot*)grid, 1234 * 1234, (Spot*)backup);
	dijkstra();
	m.erase('W');
	for (auto i : m) cout << i.dx << " " << i.dy - 1 << endl;
}