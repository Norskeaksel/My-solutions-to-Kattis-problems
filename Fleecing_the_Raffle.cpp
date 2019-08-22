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
#define fori(n) for (ll i=0;i<n;i++)
#define forj(n) for (int j=0;j<n;j++)

ld drawOne(ld mid, ld tot, ld q) {
	ld prob = mid / tot;
	fori(q - 1) {
		prob *= (tot - mid - i) / (tot - 1 - i);
	}
	return prob * q;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	ll n, q;
	cin >> n >> q;
	ll low = 1, high = 1e12;
	ll mid;
	//while (high - low > 1) {
	forj(70) {
		mid = (low + high) / 2;
		ll tot = n + mid;
		ld cur = drawOne(mid, tot, q);
		//cout << mid << " " << cur << endl;
		ld down = 0, up = 0;
		ll i = 1;
		while (down == up) {
			down = drawOne(mid - i, tot - i, q);
			up = drawOne(mid + i, tot + i, q);
			i++;
		}
		if (down<cur&&cur>up)
			break;
		else if (down > cur) {
			high = mid;
		}
		else if (up > cur) {
			low = mid;
		}
	}
	cout << setprecision(20) << drawOne(mid, mid + n, q);
}
/*while (1) {
	i++;
	if (mid - i < 1)
		break;
	else if (curProb == drawOne(mid - i, tot - i, q));*/