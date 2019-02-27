#include <iostream>
using namespace std;
int main() {
	int tests;
	cin >> tests;
	for (int k = 0; k < tests; k++) {


		int monthsInYear, daysInYear, daysInMonth;
		int day = 7, date = 1, counter = 0;
		cin >> daysInYear>> monthsInYear;
		for (int i = 0; i < monthsInYear; i++) {
			cin >> daysInMonth;
			for (int j = 1; j <= daysInMonth; j++) {
				date = j;
				if (day == 8) day = 1;
				if (day == 5 && date == 13) counter++;
				day++;
			}

		}
		cout << counter << endl;
	}
}