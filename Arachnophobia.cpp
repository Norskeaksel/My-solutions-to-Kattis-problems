//#include<bits/stdc++.h> includerer alt, men fungerer ikke i visual studio
#include<iostream>
#include<string>
#include <sstream>// for ting som ostream
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
#include <iomanip>
#include <stdio.h>
#include<utility>//pair<auto,auto> 
#include <iomanip>
#include <iterator>
#include <queue>
#include <functional>
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define ll long long
#define double long double

vector<pair<int, int>>node[234567] = {};//parret er vekt og endenode
int done[234567] = {};
vector<int> neighbors[234567];
int dist[234567], parent[234567];
int dist2[234567];
void dijkstra(vector<pair<int, int>>node[],vector<int>spiders) {
	fill_n(dist, 234567, 2e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for(int s:spiders) {
		dist[s] = 0;
		pair<int, int>u = { 0,s };//avstand og nummer til node u
		pq.push(u);
	}
	while (!pq.empty()) {
		pair<int, int>	u = pq.top();
		pq.pop();
		int d = u.first;
		if (d > dist[u.second]) continue;
		for (auto e : node[u.second]) {
			if (dist[e.second] > dist[u.second] + e.first) {
				dist[e.second] = dist[u.second] + e.first;
				parent[e.second] = u.second;
				pq.push({ dist[e.second],e.second });
			}
		}
	}
}
int dijkstraCheck(int start,int slutt,int time, int minlengde) {
	fill_n(dist2, 234567, 2e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		dist2[start] = 0;
		pair<int, int>u = { 0,start };//avstand og nummer til node u
		pq.push(u);
	while (!pq.empty()) {
		pair<int, int>	u = pq.top();
		pq.pop();
		int d = u.first;
		if (d > dist2[u.second]||dist[start]< minlengde) continue;
		for (auto e : node[u.second]) {
			if (dist2[e.second] > dist2[u.second] + e.first && dist[e.second]>=minlengde) {
				dist2[e.second] = dist2[u.second] + e.first;
				parent[e.second] = u.second;
				pq.push({ dist2[e.second],e.second });
			}
		}
	}
	return dist2[slutt] <= time;
		
}
//Nå som jeg har en dijksta så må jeg begynne med binærsøking eller noe
int main(){
	int n, m,t,u,v,d;
	cin >>n>> m>>t;
	fori(m) {
		cin >> u >> v >> d;
		node[u].push_back({ d,v });
		neighbors[u].push_back(v);
		node[v].push_back({ d,u });
		neighbors[v].push_back(u);
	}
	int start, slutt,k,s;
	cin >> start >> slutt >> k;
	vector<int>spiderpos;
	fori(k) {
		int s;
		cin >> s;
		spiderpos.push_back(s);
	}
	dijkstra(node, spiderpos);

	int good=0, bad=1e9+1;
	while (good+1<bad){
		int checkDist = (good + bad) / 2;
		if (dijkstraCheck(start, slutt, t, checkDist))
			good = checkDist;
		else bad = checkDist;
	}
	cout << good;
}