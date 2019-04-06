#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define ll long long
#define double long double
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

vector<pair<int, int>>node[123456];
int done[123456];
void MST(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pair<int, int>u = { 0,0 };
	pq.push(u);
	int d = 0, c = 0;
	while (!pq.empty() && c < n) {
		u = pq.top();
		pq.pop();
		if (done[u.second]++)continue;
		d = max(d, u.first);
		c++;
		for (auto i : node[u.second]) {
			pq.push(i);
		}
	}
	if (c < n)
		cout << "IMPOSSIBLE\n";
	else
		cout << d;
}
int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n, m;
	cin >> n >> m;
	fori(m) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ w,v });
	}
	MST(n);
}