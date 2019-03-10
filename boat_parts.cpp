#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int p, n;
	vector <string> part;
	cin >> p >> n;
	int c = 0, a = 1;
	for (int i = 0; i < n; i++) {
		string newpart;
		cin >> newpart;
		part.push_back(newpart);
		for (int j = 0; j < part.size(); j++) {
			if (part[i] == part[j] && i != j) break;
			if (j == part.size() - 1) c++;
			if (c == p)
			{
				cout << i+1<<endl;
				exit(0);
			}
		}
	}
	//sort(part.begin(), part.end());
	//for (int i = 1; i < part.size(); i++) {
		//if (part[i - 1] != part[i])a++;
	//}
	cout << "paradox avoided\n";
	//if (a < p) 
	//else cout << c << endl;
}