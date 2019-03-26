#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int in;
	vector<int>vec;
	for (int i = 0; i < n; i++) {
		cin >> in;
		vec.push_back(in);
	}
	int lowest = vec[n-1],highest=vec[0];
	vector<int> min,max;
	for (int i = 1; i < n; i++) {
		
		max.push_back(highest);

		if (vec[i] > highest)
			highest = vec[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (vec[i] < lowest)
			lowest = vec[i];
		min.push_back(lowest);
	}
	int pp = 0;
	reverse(min.begin(),min.end());
for (int i = 0; i < n; i++) {
		if ((!i || max[i - 1] <= vec[i]) && (i==n - 1 || min[i + 1] > vec[i]))
			pp++;
	}
	cout << pp;
}