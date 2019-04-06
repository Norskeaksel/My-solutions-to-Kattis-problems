#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define all(v) (v).begin(),(v).end()
#define fori(n) for (int i=0;i<n;i++)

int bin2dec(string bin){
	int ans=0, place = 1;
	for (int i = bin.size() - 1; i >= 0;i--) {
		ans += place * (bin[i] - '0');
		place *= 2;
	}
	return ans;
}

string bin2oct(string bin){
	string ans;
	fori(bin.size() / 3) {
		string sub = bin.substr(3 * i, 3);
		int digit = bin2dec(sub);
		ans += (digit + '0');
	}
	return ans;
}
string readInput(){
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	string bin;
	cin >> bin;
	reverse(all(bin));
	while (bin.size() % 3) {
		bin += '0';
	}
	reverse(all(bin));
	return bin;
}
int main() {
	string str=readInput();
	cout<<bin2oct(str);
}