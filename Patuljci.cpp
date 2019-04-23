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
	int d[9];
	int a;
	fori(9) {
		cin >> a;
		d[i] = a;
	}
	for (int bitmask = 0; 1 << 9; bitmask++) {//bitmask er en array med nullere og enere som representerer en integer. Her går vi gjennom alle kombinasjoner av en array med 10 bit 1<<10=2^10 
		int sum = 0,ones=0;
		int finalindex[9] = {};
		for (int i = 0; i < 9; i++) {
			if (bitmask >> i & 1) {//bitten til bitmask på index i er 1
				//her bitskiftes bitmask med i, altså har vi bitmask/2^i og & slår opp i bitmasken og sjekker om bitten på enden av den bittskiftede bitmask er 0 eller 1. 
				//Dersom bitten er 1 så 
				finalindex[i] = 1;
				ones++;
				sum += d[i];
					if (ones == 7 && sum == 100) {
						forj(9) {
							if (finalindex[j])
								cout << d[j] << endl;
						}
						exit(0);
					}
			}
		}
	}
}
