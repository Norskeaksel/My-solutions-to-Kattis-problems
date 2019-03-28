#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int x, n;
	cin >> x;
	vector <int> t,temp;
	for (int i = 0; i < x; i++) {
		cin >> n;
		t.push_back(n);
	}
	t.push_back(1e9);
	sort(t.begin(), t.end());
	for (int i = 0; i < x - 1; i++) {
		if (t[i + 1] == t[i] + 1 && t[i + 2] == t[i] + 2) temp.push_back(i + 1);
	}
	for (int i = 0; i < temp.size(); i++) {
		t[temp[i]] = 0;
	}
	int j = 0;
	while (t[j]!= 1e9) {
		if (t[j] == 0 && t[j + 1] == 0) {
			t.erase(t.begin() + j);
			j--;
		}
		j++;
	}
	//for (int i = 0; i < t.size(); i++) {
	//cout << t[i] << " ";}
	
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == 0)cout << "-";
		else if (t[i] == 1e9);
		else if (t[i+1]==0)cout << t[i];
		else cout << t[i]<<" ";
	}
}