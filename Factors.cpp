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
vector<long long>primeFactors(long long n) {
	vector<long long>svar;
	while (n % 2 == 0){
		svar.push_back(2);
		n >>2;
	}
	for (long long i = 3; i <= sqrt(n); i = i + 2) { 
		while (n%i == 0){
			svar.push_back(i);
			n /=i;
		}
	}
	if (n > 2)
		svar.push_back(n);
}
int main() {
	set<long long> factors;
	long long num,counter=0;
	while (cin >> num) {
	
}