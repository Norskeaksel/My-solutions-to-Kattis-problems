#include <iostream>
#include <string>
using namespace std;
int main() {
	int date1, date2;
	cin >> date1 >> date2;
	string text[7] = { "Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday", "Wednesday" };
	int day=1, month=1,current=0;
	string svar = "Thursday";
	int oldmonth = 1;
		while ((day != date1) || (month != date2)) {
			/*if (month > oldmonth) {
				cout << month << endl;
				oldmonth = month;
			}*/
			if (day == 28 && month == 2) {
			day = 0;
			month++;
		}
		else if (day == 30 && month % 2 == 0 && month < 7) {
			day = 0;
			month++;
		}
		else if(day==31 && month % 2 == 1 &&month<8)
		{
			day = 0;
			month++;
		}
		else if (day == 31 && month == 8) {
			day = 0;
			month++;
		}
		else if (day == 30 && (month ==9 || month== 11)) {
			day = 0;
			month++;
		}
		else if (day == 31 && month ==10 ) {
			day = 0;
			month++;
		}
		current++;
		if (current > 6)
			current = 0;
		svar = text[current];
		
		day++;
		//cout << day<<" "<< month<<" "<<svar << endl;
	}
		cout << svar << endl;
}