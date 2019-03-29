#include <iostream>
#include<utility>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, x;
	while (1) {
		cin >> n;
		if (!n)
			break;
		pair<int, int>dummy;
		vector<pair<int, int>>l1, sortl1, l2, sortl2;
		for (int i = 0; i < n; i++) {
			cin >> x;
			dummy.first = x;
			dummy.second = i;
			l1.push_back(dummy);
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			dummy.second = x;
			l2.push_back(dummy);
		}
		//for (int i = 0; i < n; i++)cout << " first " << l1[i].first << " second " << l1[i].second;
		sort(l1.begin(),l1.end());
		//cout << endl;
		//for (int i = 0; i < n; i++)cout << " first " << l1[i].first << " second " << l1[i].second;
		sort(l2.begin(), l2.end());
		for (int i = 0; i < n; i++) {
			//cout << l1[i].second;
			l2[i].first = l1[i].second;
		}
		sort(l2.begin(), l2.end());
		for (int i = 0; i < n; i++) {
			cout << l2[i].second << endl;
		}
		cout << endl;
	}
}

/*
		
		sort(sortl1.begin(), sortl1.end());
		//for (int i = 0; i < n; i++) cout << sortl1[i].first << endl;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (l1[i].first == sortl1[j].first) {
						l2[i].first = j;
					}
				}
			}
			sort(l2.begin(), l2.end());
			cout << "BEGIN\n";
			for (int i = 0; i < n; i++)
				cout << l2[i].second << endl;
			cout << endl;*/

/*vector<pair<int, int>>l1,sortl1, l2,sortl2;

for (int i = 0; i < n; i++) {
	cin >> x;
	dummy.first = x;
	dummy.second = i;
	l1.push_back(dummy);
}
for (int i = 0; i < n; i++) {
	cin >> x;
	dummy.second = x;
	dummy.first = 0;
	l2.push_back(dummy);
}
sort(l1.begin(), l1.end());
for (int i = 0; i < n; i++) {
	l2[i].first = l1[i].second;
}
sort(l2.begin(), l2.end());
for (int i = 0; i < n; i++)
	cout << l2[i].second << endl;
cout << endl;*/