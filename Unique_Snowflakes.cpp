#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include <queue>
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define ll long long
#define double long double
#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

long main() {
#if defined _MSC_VER 
	freopen("C:\Users\ahsor\Downloads\in.jpg", "r", stdin);//read all input form this local file 
#endif
	int n = 1;
	while(n--){
		int t;
		cin >> t;
		vector<int>input;
		fori(t) {
			int a;
			cin >> a;
			input.push_back(a);
		}
		int start = 0,j=0;
		set<int>dummySet;
		map<int, int> dummyMap;
		vector<map<int,int>> nr2index;
		nr2index.push_back(dummyMap);
		vector<set<int>>subset;
		subset.push_back(dummySet);
		fori(t){
			if(subset[j].count(input[i])==0){
				subset[j].insert(input[i]);
				nr2index[j][input[i]] = i;
			}
			else{
				subset.push_back(dummySet);
				nr2index.push_back(dummyMap);
				i = nr2index[j][input[i]];
				j++;
			}
		}
		int ans = 0;
		fori(subset.size()){
			//ans = max(ans, subset[i].size());
			if (subset[i].size() > ans)
				ans = subset[i].size();
		}
		cout << ans << endl;
	}
}