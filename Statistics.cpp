#include <iostream>
#include <vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main() {
	int i=1,n;
	while (cin >> n) {
		vector <int>t;
		string str;
		getline(cin, str);
		stringstream ss(str);
		while (ss>>n) {
			t.push_back(n);
		}
		sort(t.begin(), t.end());
		int min = t[0];
		int max = t[t.size() - 1];
		cout << "Case "<<i<<": " << min << " " << max <<' '<< max - min<<endl;
		i++;
	}
}