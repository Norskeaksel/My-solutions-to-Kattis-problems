#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int intime=0,truetime=0;
	char problem;
	string answer;
	int penalty = 0,points=0;
	vector<char> problems;
	while (cin >> intime) {
		if (intime == -1)
			break;
		cin >> problem >> answer;
		if (answer == "right") {
			truetime += intime;
			points++;
			for (int i = 0;i< problems.size(); i++) {
				if (problems[i] == problem)
					penalty += 20;
		}
		}
		else {
			problems.push_back(problem);
		}
	}
	cout << points<<" "<<truetime + penalty << endl;
}