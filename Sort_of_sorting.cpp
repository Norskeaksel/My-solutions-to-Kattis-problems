#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Name {
	string name;
	int index;
};
bool operator<(const Name&a, const Name&b) {
	if (a.name.substr(0, 2) == b.name.substr(0, 2))
		return a.index < b.index;
	return a.name.substr(0,2) < b.name.substr(0,2);
}

template <typename T>void merge(vector<T> &names, int vecstart, int halfspilt, int vecend) {
	vector<T>sortednames;
	int a = vecstart, b = halfspilt;
	for (int i = vecstart; i < vecend; i++) {
		if(b>=vecend)
			sortednames.push_back(names[a++]);
		else if(a>=halfspilt)
			sortednames.push_back(names[b++]);
		else if (names[a] < names[b])
			sortednames.push_back(names[a++]);
		else
			sortednames.push_back(names[b++]);
	}
	for(int i=vecstart;i<vecend;i++)
		names[i] = sortednames[i- vecstart];
}

template <typename T> void  mergeSort(vector<T> &names, int vecstart, int vecend) {
	if (vecstart+1 < vecend) {
		int halfsplit = (vecstart + vecend) / 2;
		mergeSort(names, vecstart, halfsplit);
		mergeSort(names, halfsplit, vecend);
		merge(names, vecstart, halfsplit, vecend);
	}
	
}
int main() {
	int n;
	while (cin >> n) {
		if (!n)
			exit(0);
		vector<Name>names,copy;
		for (int i = 0; i < n; i++) {
			Name str;
			cin >> str.name;
			str.index = i;
			names.push_back(str);
		}
		mergeSort(names, 0, names.size());

		for (int i = 0; i < names.size(); i++) {
			cout << names[i].name << endl;
		}
		cout << endl;
	}
}