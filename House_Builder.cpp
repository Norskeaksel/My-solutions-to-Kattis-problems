#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int t,tr, s,sr, f,sl,counter=0;
	cin >> t >> s >> f;
	vector <int> tomt, rad;
	for (int i = 0; i < t; i++) {
		cin >> tr;
		tomt.push_back(tr*tr*2);
	}
	for (int i = 0; i < s; i++) {
		cin >> sr;
		rad.push_back(sr*sr*2);
	}
	for (int i = 0; i < f; i++) {
		cin >> sl;
		int fr = sl*sl;
		rad.push_back(fr);
	}
	sort(tomt.rbegin(), tomt.rend());
	sort(rad.rbegin(), rad.rend());

	for (int i = 0; i < tomt.size(); i++) {
		for (int j = 0; j < rad.size(); j++) {
			if (rad[j] < tomt[i]) {
				rad[j] = 101*101*2;
				counter++;
				break;
			}
		}
	}
	cout << counter << endl;
}