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

ll timePerQ;
ll macs;
ll secs;
ll qes;

bool goodTime(ll time) {
	ll qCap =  time/timePerQ*macs;
	if (qCap < qes) return 0;
	ll timeCap = time * macs;
	ll timeLeft = timeCap- qes *timePerQ;
	return timeLeft >= secs;
}
ll binarySearch(ll fail=-1, ll pass=1e10) {
	ll ans;
	while (pass - fail > 1) {
		ll time = (fail + pass) / 2;
		if (goodTime(time)) {
			ans = time;
			pass = time;
		}
		else {
			fail = time;
		}
	}
	return ans;
}

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	cin >> timePerQ >> macs >> secs >> qes;//q,m,s,l'
	cout << binarySearch();
}