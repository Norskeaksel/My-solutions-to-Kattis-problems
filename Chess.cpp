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
#define f first
#define s second
#define ll long long
#pragma warning(disable:4996)
set<pair<char, int>>addset(int startletter, int startnumber, int direction, map<int, char>tochar) {
	set<pair<char, int>>reachable;
	switch (direction) {
	case 1://upleft
		while (--startletter > 0 && ++startnumber < 9) {
			reachable.insert({ tochar[startletter],startnumber });
		}
		break;
	case 2://upright
		while (++startletter < 9 && ++startnumber < 9) {
			reachable.insert({ tochar[startletter],startnumber });
		}
		break;
	case 3://downright
		while (++startletter < 9&&--startnumber>0){
			reachable.insert({ tochar[startletter],startnumber });
		}
		break;
	case 4://downleft
		while (--startletter > 0 && --startnumber > 0) {
			reachable.insert({ tochar[startletter],startnumber });
		}
		break;
	default:
		break;
	}
	return reachable;
}
int main() {
#if defined _MSC_VER
	//freopen("Text.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		map<char, int>toint;
		map<int, char> tochar;
		fori(8) {
			toint['A' + i] = i+1;
			tochar[i+1] = 'A' + i;
		}
		map < pair<char, int>, set<pair<char, int>>>bigmap;
		pair<char, int> start, goal;
		cin >> start.first >> start.second >> goal.first >> goal.second;
		int startletter = toint[start.first];
		int startnumber = start.second;
		int direction[4] = { 1,2,3,4 };//upleft,upright,downright,downleft
		set<pair<char, int>>reachable, newpart, moves2;
		fori(4) {
			newpart = addset(startletter, startnumber, direction[i], tochar);
			reachable.insert(all(newpart));
		}
		bigmap[start] = reachable;
		for (auto i : reachable) {
			fori(4) {
				newpart = addset(startletter, startnumber, direction[i], tochar);
				moves2.insert(all(newpart));
			}
			bigmap[i] = moves2;
		}
		if (start == goal) {
			cout << "0 " << start.f << " " << start.s<<endl;
		}
		else if ((toint[start.f] + start.s) % 2 != (toint[goal.f] + goal.s) % 2) {
			cout << "Impossible\n";
		}
		else if (bigmap[start].count(goal)) {
			cout << "1 " << start.f << " " << start.s << " " << goal.f << " " << goal.s<<endl;
		}
		else {
			cout << "2 " << start.f << " " << start.s<<" ";
			for (auto i : bigmap[start]) {
				forj(4) {
					newpart = addset(toint[i.f], i.s, direction[j], tochar);
					bigmap[i].insert(all(newpart));
				}
				/*cout << "i=" << i.f << "," << i.s << endl;
				for (auto k : bigmap[i]) {
					cout << k.f << k.s;
				}*/
				if (bigmap[i].count(goal)) {
					cout << i.f << " " << i.s << " " << goal.f << " " << goal.s << endl;
					break;
				}
			}
		}
	}
}
