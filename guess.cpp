#include<iostream>
#include<string>
using namespace std;
int main() {
	string in = "";
	int upper=1001,lower=0,out = 500;
	while (1){
		cout << out<<endl;
		cin >> in;
		if (in == "correct")
			exit(0);
		if (in == "higher") {
			lower = out;
			out = (upper + out) / 2;
		}
		if (in == "lower") {
			upper = out;
			out = (lower + out) / 2;
		}
	}
}