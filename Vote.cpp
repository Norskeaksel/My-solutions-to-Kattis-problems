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

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int m = 0;
		int sum = 0;
		bool no_winner = 0;
		int index = 0;
		fori(n){
			vector<int>canditate;
			int a;
			cin >> a;
			sum += a;
			if(m<a){
				no_winner = 0;
				m = a;
				index = i;
			}
			else if(m==a){
				no_winner = 1;
			}
		}
		if (no_winner)
			cout << "no winner\n";
		else if (m > sum - m) {
			cout << "majority winner " << ++index << endl;
		}
		else
			cout << "minority winner " << ++index << endl;
	}
}