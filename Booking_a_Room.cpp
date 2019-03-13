#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int rooms, totb,b,counter=0;
	vector <int> boro;
	cin >> rooms >> totb;
	for (int i = 0; i < totb; i++) {
		cin >> b;
		boro.push_back(b);
	}
	/*for (int i = 0; i < boro.size(); i++) {
		cout << boro[i]<<" ";
	}
	cout <<endl<< binary_search(boro.begin(), boro.end(), 1);//Hvorfor returnerer denne false?
	exit(0);*/
	for (int i = 1; i <= rooms; i++) {
		if (binary_search(boro.begin(), boro.end(), i));
		else {
			cout << i;
			exit(0);
		}
	}
	cout << "too late\n";
}