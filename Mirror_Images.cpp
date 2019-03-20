#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,t=0;
	cin >> n;
	while (n--) {
		t++;
		cout << "Test " << t << endl;	
		int r, c;
		cin >> r >> c;
		string in="",out="",str;
		for (int i = 0; i < r; i++) {
			cin >> str;
			in += str;
		}
		out = in;
		int s = in.size()-1;
		for (int i = 0; i < in.size(); i++) {
			out[i] = in[s];
			s--;
		}
		for (int j = 0; j < out.size(); j++) {
			cout << out[j];
			if (!((j + 1) % c) && j != 0||c==1) {
				cout << endl;
			}
		}
	}
}