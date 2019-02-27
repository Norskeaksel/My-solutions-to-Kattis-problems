#include <iostream>
using namespace std;
int main() {
	int empty, found, required,counter=0;
	cin >> empty >> found >> required;
	empty += found;
	while (empty>= required) {
		empty -= required;
		counter++;
		empty++;
		//if (counter%required == 0)
			//counter++;
	}
	cout << counter << endl;
}