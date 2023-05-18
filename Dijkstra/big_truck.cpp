#include <functional>
#include<iostream>
#include<string>
#include<queue>
#define ll long long
using namespace std;
vector<pair<ll, ll>>node[234567];
ll dist[234567];
ll items[234567];
void dijkstra(ll start) {
	fill_n(dist, 234567, 1e11);
	dist[start] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,greater<pair<ll, ll>>> pq;
	pair<ll, ll> u = {0,start };
	pq.push(u);
	while (!pq.empty()) {
		pair<ll, ll> edge;
		edge = pq.top();
		pq.pop();
		if (dist[edge.second] < edge.first) continue;
		for (auto e : node[edge.second]) {
			if (dist[e.second] > dist[edge.second] + e.first) {
				dist[e.second] = dist[edge.second] + e.first;
				pq.push({ dist[e.second],e.second });
			}
		}
	}
}

int main() {
	ll n;
	cin >> n;
	ll start=1, stop=n, it;
	for (ll i = 1; i <= n; i++) {
		cin >> it;
		items[i] = it;
	}
	cin >> n;

	for (ll i = 1; i <= n; i++) {
		ll u, v, d;
		cin >> u >> v >> d;
		node[u].push_back({ d*1e6 - items[v],v });
		node[v].push_back({ d*1e6 - items[u],u });
	}
	dijkstra(start);
	//for (int i = 1; i < n;i++) {cout << dist[i] << " ";}
	
	if (dist[stop] == 1e11)
		cout << "impossible\n";
	else {
		int finaldist = (dist[stop] - 1) / (ll)(1e6) + 1;
		int finalitems=finaldist*(ll)(1e6)- dist[stop];
		cout << finaldist << " "<<finalitems+items[1]<<"\n";
	}
}
