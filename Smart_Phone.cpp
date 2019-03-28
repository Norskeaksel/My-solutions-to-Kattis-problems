#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int addonly(string sofar, string finalword, int counter) {
	while (sofar != finalword) {
		sofar = sofar + finalword[sofar.size()];
		counter++;
		//cout << counter << sofar << endl;
		//system("pause");
	}
	return counter;
}
string subtract(string sofar) {
	return sofar.substr(0, sofar.size() - 1);

}
int main() {
	int test, counter = 0;
	cin >> test;
	string finalword, sofar, firstop, secondop, thirdop, add, remove, temp;
	string remtemp, partfinal;
	for (int i = 0; i < test; i++) {
		cin >> finalword >> sofar >> firstop >> secondop >> thirdop;
		vector<string> option{ sofar,firstop ,secondop,thirdop };
		vector<int>times;
		for (int j = 0; j < 4; j++) {
			int  counter = 0, check = 0, removeoption;
			if (j > 0)counter = 1;
			remtemp = option[j];
			partfinal = finalword.substr(0, remtemp.size());
			while (remtemp != partfinal ) {
				if (remtemp.size() == 1) {
					remtemp = finalword[0];
					counter += 2;
					break;
				}
				remtemp = subtract(remtemp);
				partfinal = finalword.substr(0, remtemp.size());
				counter++;
			}
			counter=addonly(remtemp, finalword, counter);
			times.push_back(counter);
		}
		sort(times.begin(), times.end());
		cout << times[0]<< endl;
	}
}
/*
if (sofar.size() == 1) {
cout << addonly(sofar, finalword, counter)+1<<endl;
exit(0);
}
int a = 0, b = 0, c = 0, d = 0, e = 0;
temp = finalword;
add = sofar + finalword[sofar.size()];
remove = sofar.erase(sofar.size() - 1, 1);
for (int j = 0; j < sofar.size() + 1; j++) {
if (add[j] == finalword[j]) a++;
else a=-100;
}
/*for (int j = 0; j < sofar.size() - 1; j++) {
if (remove[j] == finalword[j]) b++;
else b--;
}
temp = finalword + "ææææææææææææææææææææææææææææææææææææææææææææææææ";
if (counter == 0) {
for (int j = 0; j < firstop.size(); j++) {
if (firstop[j] == temp[j]) c++;
else c--;
}
for (int j = 0; j < secondop.size(); j++) {
if (secondop[j] == temp[j]) d++;
else d--;
}
for (int j = 0; j < secondop.size(); j++) {
if (secondop[j] == temp[j]) e++;
else e--;
}
}
temp = sofar;
if (a >= b && a >= c && a >= d && a >= e) temp = add;
else if (b >= a && b >= c && b >= d && b >= e) temp = remove;
else if (c >= a && c >= b && c >= d && c >= e) temp = firstop;
else if (d >= a && d >= b && d >= c
&& d >= e) temp = secondop;
else if (e >= a && e >= b && e >= c && e >= d) temp = thirdop;
if (change == 1) {
if (a > b) temp = add;
else temp = remove;
}
int tempsize = temp.size();
if (change == 0) {
for (int j = 0; j < tempsize - 1; j++) {
if (temp[j] != finalword[j]) {
int sofarsize = tempsize;
if (firstop.size() <= sofarsize) temp = firstop; change = 1;
if (secondop.size() <= sofarsize && secondop.size() < firstop.size())temp = secondop; change = 1;
if (thirdop.size() <= sofarsize && thirdop.size() < firstop.size() && thirdop.size() < secondop.size())temp = thirdop; change = 1;
}
if (change == 1) break;
}
}
sofar = temp;
cout << counter+1<<" "<<sofar<<endl;
system("pause");
if (sofar.size() == 1) sofar[0] = finalword[0];
counter++;
}
cout << counter << endl;
}*/