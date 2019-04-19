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
#define x first
#define y second
#pragma warning(disable:4996)
pair<double, double> polToRec(double theta, double r) {
	pair<double, double>coord;
	//theta +=90;
	theta = -theta/180* acos(-1);
	coord.x = r * sin(theta);
	coord.y = r * cos(theta);
	return coord;
}
pair <double, double> operator += (pair<double, double>&a, pair<double, double>&b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}
int main() {
#if defined _MSC_VER
	freopen("Text.txt", "r", stdin);
#endif
	double t;
	cin >> t;
	while (t--) {
		pair<double, double>svar = { 0,0 },temp;
		double n;
		cin >> n;
		double theta,oldtheta=0, r;
		fori(n) {
			cin >> theta>> r;
			theta+= oldtheta;
			oldtheta = theta;
			temp= polToRec(theta, r);
			svar += temp;
		}
		cout << setprecision(14) << svar.x << " " << svar.y << endl;
	}
}
