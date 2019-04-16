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
		vector<double>allsums;
		int cust,in;
		cin >> cust;
		fori(cust) {
			double onesum = 0;
			int pice;
			cin >> pice;
			forj(pice) {
				cin >> in;
				onesum += in;	
			}
			allsums.push_back(onesum);
		}
		sort(allsums.begin(), allsums.end());
		int si = allsums.size();
		double svar = 0;
		fori(si-1) {
			allsums[i + 1] += allsums[i];
			svar += allsums[i];
		}
		svar += allsums[si - 1];
		//fori(si) { cout << allsums[i] << " "; }
		cout << setprecision(20) << svar / double(cust) << endl;
	}
}
