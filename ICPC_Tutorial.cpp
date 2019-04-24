//#include<bits/stdc++.h> includerer alt, men fungerer ikke i c++
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
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define ll long long
#define double long double
void TLE(){
	cout << "TLE\n";
	exit(0);
}
int main(){
	ll m, n, t,time=1;
	cin >> m>> n>> t;
	switch (t) {
		case 1:
			if (n > 20)
				TLE();
		forx(n) 
			time *= x;
			if (time > m)
				TLE();
		
		break;
		case 2:
			if (n > 60)
				TLE();
			fori(n) 
				time *= 2;
			if (time > m)
				TLE();
			
			break;
		case 3:
			if (pow(n, 4) > m)
				TLE();
			break;
		case 4:
			if (pow(n, 3) > m)
				TLE();
			break;
		case 5:
			if (pow(n, 2) > m)
				TLE();
			break;
		case 6:
			if (n*log2(n) > m)
				TLE();
			break;
		case 7:
			if (n > m)
				TLE();
			break;
	}
		cout << "AC\n";
}