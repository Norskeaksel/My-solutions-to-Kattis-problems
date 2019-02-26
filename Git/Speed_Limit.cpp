#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n=0,svar;
	vector<int> utskrift;
	while (n!=-1){
		cin >> n;
		int speed, hour, oldhour = 0, tottime = 0, distance = 0;
		for (int i = 0; i< n; i++) {
			cin >> speed >> hour;
			tottime = hour;
			hour -= oldhour;
			oldhour = tottime;
			distance += speed * hour;
		}
		svar = distance;
		utskrift.push_back(svar);
	}
	
for(int j=0;j<utskrift.size()-1;j++){
	cout << utskrift[j] << " miles" << endl;
}
}