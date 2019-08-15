#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
#define in(t) int t; cin >> t; while(t--)

vector<int>permutations;
void findPermutations(string str, int i, int n){
	if (i == n - 1)	{
		permutations.push_back(stoi(str));
		return;
	}
	for (int j = i; j < n; j++)	{
		swap(str[i], str[j]);// swap character at index i with current character
		findPermutations(str, i + 1, n);// recurse for string [i+1, n-1]
		swap(str[i], str[j]);// backtrack (restore the string to its original state)
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	string str;
	cin >> str;
	int s = stoi(str);
	findPermutations(str, 0, str.size());
	int ans = 1000000;
	for(auto i:permutations){
		if (i > s&&i < ans)
			ans = i;
	}
	if (ans == 1000000)
		cout << 0;
	else
		cout << ans;
}