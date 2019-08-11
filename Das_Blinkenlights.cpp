#include <iostream>
#include <vector>
using namespace std;

int main(){
	int p, q, s,cp,cq;
	cin >> p >> q >> s;
	cp = p;
	cq = q;
	vector<int>a, b;
	while (p<=s){
		a.push_back(p);
		p += cp;
	}
	while (q<=s){
		b.push_back(q);
		q += cq;
	}
	for(auto i:a){
		for(auto j:b){
			if(j==i){
				cout << "yes\n";
				exit(0);
			}
		}
	}
	cout << "no\n";
}