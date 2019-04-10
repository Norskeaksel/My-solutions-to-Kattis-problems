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

int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
}
	/*		vector<map<string, int>>mymaps;
		string a, b;
		cin >> a >> b;
		map<string, int>first;
		first[a] = 2;
		first[b] = 2;
		cout << 2 << endl;
		mymaps.push_back(first);
		fori(n) {
			map<string, int>dic, empty;
			int ina = -1, inb = -1;
			cin >> a >> b;
			forj(mymaps.size()) {
				if (mymaps[j][a])//finner mapet hvor navnene ligger
					ina = j;
				if (mymaps[j][b])
					inb = j;

				if (ina == -1 && inb == -1) {//ingen av navnene finnes fra før
					dic[a]+=2;
					dic[b]+=2;
					mymaps.push_back(dic);
				}
				else if (ina!=-1 && inb==-1) {//dersom navn a finnes og b ikke finnes
					mymaps[ina][b] = mymaps[ina][a];
					for (auto& m : mymaps[ina]) {
						//cout << m.first << " " << m.second << " ";
						m.second++;
						//cout << m.first << " " << m.second << endl;
					}
					cout << mymaps[ina][a] << endl;
				}
				else if (ina==-1 && inb!=-1) {//dersom navn b finnes og a ikke finnes
					mymaps[inb][a] = mymaps[inb][b];
					for (auto& m : mymaps[inb]) {
						m.second++;
					}
					cout << mymaps[inb][b] << endl;
				}
				else if (ina!=0 && inb!=0) {
					for (auto& m : mymaps[ina]) {
						m.second += mymaps[inb].size();

					}
					cout << mymaps[ina][a] << endl;
					mymaps[inb] = empty;
				}
			}
		}
	}*/