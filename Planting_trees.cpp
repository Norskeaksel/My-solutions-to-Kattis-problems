#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int numberoftrees;
	int tree, temp,days=0;
	cin >> numberoftrees;
	vector<int> daystogrow;
	for (int i = 0; i < numberoftrees; i++) {
		cin >> tree;
		daystogrow.push_back(tree);
	}
	sort(daystogrow.rbegin(), daystogrow.rend());

	for (int i = 0; i < daystogrow.size(); i++) {
		//cout<<daystogrow[i];
		daystogrow[i] += i + 1;
		if (daystogrow[i] > days) days = daystogrow[i];
	}
	cout << days + 1 << endl;
}