#include<iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	set<string>status;
	string comming, name, out;
	for (int i = 0; i < t; i++) {
		cin >> comming >> name;
		if (comming == "entry") {
			out = "entered";
			if (status.count(name)) {
				cout << name << " " << out << " (ANOMALY)\n";
			}
			else {
				cout << name << " " << out << endl;
				status.insert(name);
			}
		}
		if (comming == "exit") {
			out = "exited";
			if (status.count(name)){
				cout << name << " " << out<<endl;
				status.erase(name);
			}
			else {
				cout << name << " " << out << " (ANOMALY)\n";
			}
		}
	}
}