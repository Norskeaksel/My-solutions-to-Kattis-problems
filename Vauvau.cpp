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
int isAgr(int agr, int calm, int entryTime) {
	int svar= --entryTime % (agr + calm);
	return svar<agr;
}
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	int Aagr, Acalm, Bagr, Bcalm;
	cin >> Aagr >> Acalm >> Bagr >> Bcalm;
	int a, b, c;
	fori(3) {
		int svar = 0;
		cin >> a;
		svar += isAgr(Aagr, Acalm, a);
		svar+= isAgr(Bagr, Bcalm, a);
		if (svar == 0) cout << "none\n";
		if (svar == 1) cout << "one\n";
		if (svar == 2) cout << "both\n";
	}
}
