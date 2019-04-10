#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int start, goal;
	cin >> start >> goal;
	int up = start, down = start;
	int countup = 0,countdown=0;
	while(up!=goal){
		up++;
		countup++;
		if(up==360){
			up = 0;
		}
	}
	while(down!=goal){
		down--;
		countdown--;
		if(down==-1){
			down = 359;
		}
	}
	if (abs(countdown) < abs(countup))
		cout << countdown;
	else
		cout << countup;
}