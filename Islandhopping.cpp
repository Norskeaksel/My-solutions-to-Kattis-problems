#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define ll long long
#define double long double
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)


struct Edge {
	double end;
	double dist;
	double start;
};
bool operator<(Edge a, Edge b) {
	return a.dist > b.dist;
}
struct Circle {//reused class from another problem
	double x;
	double y;
	double r = 0;
	int nr;
	vector<Edge> neighbors;
	int done = 0;
};

void MST(vector<Circle>graph) {
	priority_queue<Edge> pq;
	pq.push({ 0,0 });
	double dist = 0;
	unsigned int included = 0;
	while (included < graph.size()) {
		Edge u = pq.top();
		pq.pop();
		if (graph[u.end].done)continue;
		included++;
		dist += u.dist;
		graph[u.end].done = 1;
		for (auto e : graph[u.end].neighbors) {
			if (!graph[e.end].done) {
				pq.push(e);
			}
		}
	}
	cout << setprecision(20) << dist << endl << endl;
}
inline double findDist(const Circle& a, const Circle& b) {
	double xdist2 = pow(a.x - b.x, 2);
	double ydist2 = pow(a.y - b.y, 2);
	double dist = sqrt(xdist2 + ydist2);
	return dist - a.r - b.r;
}
int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<Circle> graph;
		fori(n) {
			double x, y, r = 0;//r is just leftover code
			cin >> x >> y;
			Circle a = { x, y, r,i };
			for (auto &j : graph) {
				Edge e = { j.nr };
				e.start = a.nr;
				e.dist = findDist(a, j);
				a.neighbors.push_back(e);
				Edge e2 = { a.nr,e.dist,j.nr };
				j.neighbors.push_back(e2);
			}
			graph.push_back(a);
		}
		/*for (auto i : graph) {
			cout << i.nr<<": ";
			for (auto j:i.neighbors){
				cout <<graph[j.end].nr<<" "<< j.dist << " ";
			}
			cout << endl;
		}*/
		MST(graph);
	}
}