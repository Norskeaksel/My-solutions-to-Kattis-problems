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
using namespace std;

#define fori(n) for (int i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)
#define fork(n) for (int k=0;k<n;k++)

int main() {
	long long p,a,b,svar=1e16;
	cin >> p;
	a = sqrt(p);
	b = a;
	fori(sqrt(p)) {
		if(a * b-p>=0)
			svar = min(svar, a * b-p);
		//cout << "a= " << a << " b= " << b <<" a*b= "<<a*b<<" a*b-p= "<<a*b-p<< endl;
		//system("pause");
		if (a*b < p) {
			if (a < 2 * b)
				a++;
			else
				b++;
		}
		else if (a*b > p) {
			if (b > a / 2)
				b--;
			else
				a--;
		}
		else if (a*b == p)
			break;
	}
	cout << svar<<endl;
}