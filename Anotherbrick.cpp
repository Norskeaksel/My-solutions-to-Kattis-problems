#include <iostream>
using namespace std;

int main(){
	int h, w, n,a,s=0,c=0;
	cin >> h >> w >> n;
	while (n--){
		cin >> a;
		s += a;
		if (s == w) {
			c++;
			if (c == h && s == w) {
				cout << "YES\n";
				exit(0);
			}
			s = 0;
		}
		if(s>w){
			cout << "NO\n";
			exit(0);
		}
	}
}