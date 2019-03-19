#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include <set>
#include <map>
#include<algorithm>
#include <stdio.h> 
using namespace std;
struct myClass {
	string project;
	int people;
};
vector<myClass> bubbleSort(vector<myClass> sortThis) {
	int n = sortThis.size();
	for (int i = 0; i < n - 1; i++)
		// Last i elements are already in place    
		for (int j = 0; j < n - i - 1; j++)
			if ((sortThis[j].project> sortThis[j + 1].project)  && sortThis[j].people == sortThis[j + 1].people) {
				myClass temp = sortThis[j];
				sortThis[j] = sortThis[j + 1];
				sortThis[j + 1] = temp;
			}
	return sortThis;
}
int main() {
	int numOfStud[1000] = {};
	pair<string, int> line;
	line.first = "";
	line.second = 0;
	vector<string>allInfo;
	vector<string>projects;
	vector<string>allNames;
	while (line.first != "0"&&line.first != "1") {
		getline(cin, line.first);
		allInfo.push_back(line.first);
	}
	int proCount = 1;
	for (int i = 0; i < allInfo.size(); i++) {
		if (allInfo[i][0] > 90)
			allNames.push_back(allInfo[i]);
		else if (allInfo[i][0] == '1' || allInfo[i][0] == '0');
		else {
			projects.push_back(allInfo[i]);
			allNames.push_back("DIVIDE");
			proCount++;
		}
	}
	//for (int i = 0; i < projects.size(); i++) cout << projects[i] << endl;
	allNames.push_back("DIVIDE");
	//for (int i = 0; i < allNames.size(); i++) cout << allNames[i] <<" proCount "<<proCount<< endl;
	int j = 0;
	for (int i = 0; i < proCount; i++) {
		set<string>trueNames;
		while (allNames[j] != "DIVIDE") {
			if (trueNames.count(allNames[j]))
				allNames[j] = "DELETED";
			trueNames.insert(allNames[j]);
			j++;
		}
		j++;
	}

	set<string>remainingNames;
	set<string>duplicateNames;
	for (int i = 0; i < allNames.size(); i++) {
		if (remainingNames.count(allNames[i]))
			duplicateNames.insert(allNames[i]);
		remainingNames.insert(allNames[i]);
	}
	//for (auto i : duplicateNames) cout << i << endl;
	for (int i = 0; i < allNames.size(); i++) {
		if (allNames[i] == "DIVIDE");
		else if (duplicateNames.count(allNames[i]))
			allNames[i] = "DELETED";
		remainingNames.insert(allNames[i]);
	}
	int p = -1;

	for (int i = 0; i < allNames.size(); i++) {
		if (allNames[i] == "DIVIDE")
			p++;
		else if (allNames[i] == "DELETED");
		else
			numOfStud[p]++;
	}
	vector<myClass> finaly;
	myClass input;
	for (int i = 0; i < projects.size(); i++) {
		input.project = projects[i];
		input.people = numOfStud[i];
		finaly.push_back(input);
		//cout << finaly[i].project << " " << finaly[i].people << endl;
	}
	sort(finaly.rbegin(), finaly.rend(),
		[](myClass const & a, myClass const & b) -> bool
	{ return a.people < b.people; });
	string s1 = "ABC", s2 = "BC";
	//cout << (s2 > s1);
	finaly = bubbleSort(finaly);
	for (int i = 0; i < finaly.size(); i++)cout << finaly[i].project << " " << finaly[i].people << endl;
	if (line.first != "0")
		main();
}

	/*pair<vector<int>, vector<int>> IndexPeople;
	for (int i = 0; i < projects.size(); i++) {
		IndexPeople.first.push_back( i);
		IndexPeople.second.push_back (numOfStud[i]);
	}
	//Fiks sortering
	*/
	//sort(IndexPeople.second.rbegin(), IndexPeople.second.rend());
	//for (int i = 0; i < projects.size(); i++)cout << IndexPeople.first[i] << " " << IndexPeople.second[i] << endl;

	/*while (line.first != "1" && line.first != "0") {
		int currentProject = -1;
		getline(cin, line.first);
		if (line.first[0] < 91) {
			currentProject++;
			projects.push_back(line.first);
		}
		//else
			//allNames[currentProject].insert(line);
	}
	if (line.first == "1")
		main();*/
	//for (int i = 0; i < allNames.size(); i++)cout << allNames[i] << endl;
	/*plan
	1 lag en vektor som inneholder alle navn separert fra de ulike proskjektene*
	2 for hvert proskjekt, slett kopier av navn*
	3 gå gjennom all infoen og slett alle navn som optrer flere ganger*
	4 tell hvor mange navn som kommer etter hvert proskjekt
	5 finn ut hvor mange navn som kommer etter hvert proskjet
	6 Skriv ut hvert proskjet og antall navn
	*/
	/*bool operator>(string s1, string s2) {
		int l = min(s1.size(), s2.size());
		int i = 0;
		while (s1[i] != s2[i]) {
			i++;
			if (i == 1)
				return 0;
		}
		if (s1[i] < s2[i])
			return true;
		else
			return false;
	}*/