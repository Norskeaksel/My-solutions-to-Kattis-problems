#include <iostream>
#include <vector>
using namespace std;
int main(){
	long long cappacity, stops;
	cin >> cappacity >> stops;
	long long onTrain = 0;
	for(int i=1;i<=stops;i++){
		long long left, entered, stay;
		cin >> left >> entered >> stay;
		if(left>onTrain){
			cout << "impossible";
			exit(0);
		}
		onTrain = onTrain - left + entered;
		if(onTrain<0 || onTrain>cappacity || (stay>0 && onTrain<cappacity)){
			cout << "impossible";
			exit(0);
		}
		if (i == stops && (stay > 0 || onTrain>0)) {
			cout << "impossible";
			exit(0);
		}
	}
	cout << "possible";
}