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
ll dist[1234567];
vector<pair<ll, ll>>node[1234567];
void dijkstra(int start) {
	fill_n(dist, 1234567, 1e18);
	dist[start] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pair<ll, ll> u = { 0,start };
	pq.push(u);
	while (!pq.empty()) {
		pair < ll, ll > u = pq.top();//dist to this node and this node nr
		pq.pop();
		int d = u.first;//dist to this node
		int nr=u.second;//this node nr
		if (dist[u.second] < u.first)continue;//dersom det er en lettere vei å komme seg til neste node enn å gå via nåværende node så skal vi ikke prossessere den nåverende noden
		for (auto e : node[u.second]) {
			if (dist[e.second] > dist[nr] +e.first ) {
				dist[e.second] = dist[nr]+e.first;
				pq.push({ dist[e.second],e.second });
				//cout << "node: " << e.second << " avstand: " << dist[e.second]<<endl;
			}
		}
	}
}

int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	ll  ncity, mroad, flight, start, tend;
	cin >> ncity >> mroad >> flight >> start >> tend;
	int u, v, d, f = 2e5;
	fori(mroad) {
		cin >> u >> v >> d;
		node[u].push_back({ d,v });
		node[v].push_back({ d,u });
		node[u+f].push_back({ d,v+f });
		node[v+f].push_back({ d,u+f });
	}
	fori(flight) {
		cin >> u >> v;
		node[u].push_back({ 0,v + f });
	}
	dijkstra(start);
	//fori(10) {cout << dist[i] << " ";}
	//cout << dist[tend+f];
	cout <<min(dist[tend], dist[tend + f]);
}
