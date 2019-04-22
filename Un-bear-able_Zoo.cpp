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
	int n, c = 0;
	while (cin >> n) {
		if (!n)
			exit(0);
		map<string, int>mymap;
		cin.ignore();
		c++;
		fori(n) {
			string t;
			getline(cin, t);//dersom getline(cin,t) kommer etter en cin så må vi skrive dummy getline for å bli kvitt ting, eller skrive en cin.ignore()
			stringstream ss(t); //Alle ordene fra t er nå lagret i ss
			string word; //merk dersom vi setter ss>>word så blir det første ordet i ss overført til word
			vector<string> line;
			while (ss >> word) { //dette blir litt som å skrive cin>>word der ikke brukeren men ss sender inn ord
				forj(word.size())
					word[j] = tolower(word[j]);
				line.push_back(word);// push_back legger til et element på slutten av vektoren words
			}
			mymap[line[line.size() - 1]]++;
		}
		cout<< "List "<< c<<":\n";
		for (auto m : mymap) {
			cout << m.first << " | " << m.second<<endl;
		}
	}
}
