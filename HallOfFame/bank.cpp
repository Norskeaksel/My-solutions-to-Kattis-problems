#include<iostream>
#include <utility>
#include<algorithm>
#include<vector>
#include<queue>
#include <ctime>
#include <set>
using namespace std;
int main() {
	priority_queue<pair<int, int>> pq,pq2;
	pair<int, int>d;
	int n, timeLeft;
	cin >> n >> timeLeft;
	while (n--) {
		int money, time;
		cin >> money >> time;
		d.first = time;
		d.second = money;
		pq.push(d);
	}
	set<int>takenTimes;
	int currentTime = -1;
	while (!pq.empty()) {
		d = pq.top();
		pq.pop();
		if(d.first<0)
			break;
		if(takenTimes.count(d.first)){
			d.first--;
			pq.push(d);
		}
		else{
			takenTimes.insert(d.first);
			pq2.push(d);
		}
	}
	int ans = 0;
	while(!pq2.empty()){
		d = pq2.top();
		pq2.pop();
		//cout << d.first << " " << d.second << endl;
		if(d.first<=timeLeft){
			ans += d.second;
			timeLeft--;
		}
		if (!timeLeft)
			break;
	}
	cout << ans;
}