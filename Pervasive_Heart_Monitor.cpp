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
	string s;
	while (getline(cin, s)) {
		stringstream ss(s); //Alle ordene fra t er nå lagret i ss
		string word; //merk dersom vi setter ss>>word så blir det første ordet i ss overført til word
		vector<string> line;
		while (ss >> word) //dette blir litt som å skrive cin>>word der ikke brukeren men ss sender inn ord
			line.push_back(word);// push_back legger til et element på slutten av vektoren words
		double svar=0;
		double denominator = line.size();
		string name;
		string::size_type sz;
		fori(line.size()) {
			if (line[i][0] > 47 && line[i][0] < 58) {
				double a = stod(line[i]);
				svar += a;
			}
			else {
				denominator--;
				name += " "+line[i];
			}
		}
		cout << setprecision(18)<<svar / denominator << name<<endl;
	}
	
}
