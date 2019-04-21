#include <iostream>
using namespace std;

int main(){
	int n,s=0;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		if (a < 0)
			s += a * -1;
	}
	cout << s;
}