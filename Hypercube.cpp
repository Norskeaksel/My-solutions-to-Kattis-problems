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

long long binToDec(vector<ll>bin) {
	long long c = 1, sum = 0;
	for (int i = bin.size() - 1; i >= 0; i--) {
		sum += bin[i] * c;
		c *= 2;
	}
	return sum;
}
int main() {
#if defined _MSC_VER
	//freopen("Text.txt", "r", stdin);
#endif
	ll n;
	string a, b;
	cin >> n >> a >> b;
	a = "0" + a;
	b = "0" + b;
	vector<ll> abin, bbin;
	fori(a.size() - 1) {
		ll ny = (a[i] - '0' + a[i + 1] - '0')%2;
		abin.push_back(ny);
		a[i + 1] = ny+'0';
	}
	fori(b.size() - 1) {
		ll ny = (b[i] - '0' + b[i + 1] - '0') % 2;
		bbin.push_back(ny);
		b[i + 1] = ny + '0';
	}
	/*fori(abin.size()) { cout << abin[i] << " "; }
	cout << endl;
	fori(bbin.size()) { cout << bbin[i] << " "; }
	cout << endl;*/
	ll svara = binToDec(abin), svarb = binToDec(bbin);
	//cout << svara << " " << svarb<<endl;
	cout << abs(svara - svarb)-1;
}
