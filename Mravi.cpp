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
struct vertex{
	long double flow;
	long double leaf;
	int spes;
	int parent=-2;
};
long double findFlow(vertex node, long double &current, vertex nodes[1234]) {//hvorfor &
	int par = node.parent;
	if (par != -2) {
		//cout << par << endl;
		if (node.spes == 1&& current>1) {
			current = sqrt(current)/(node.flow / 100);
		}
		else {
			current /= (node.flow / 100);
		}
		findFlow(nodes[par], current, nodes);
	}
	return current;
}
int main() {
	int n;
	cin >> n;
	vertex nodes[1234];
	int a, b, x, t;
	//int biggestNode = 0;
	fori(n-1) {
		cin>> a >> b >> x >> t;
		int slutt = max(a, b);
		int start = min(a, b);
		nodes[slutt-1].parent = start-1;
		nodes[slutt-1].flow = x;
		nodes[slutt-1].spes = t;
	}
	long double in;
	long double svar=0;
	//fori(n)cout << nodes[i].flow<< " ";
	fori(n) {
		cin >> in;
		nodes[i].leaf = in;
		if (in != -1)
			svar = max(svar, findFlow(nodes[i], in, nodes));
	}
	cout << svar;
}