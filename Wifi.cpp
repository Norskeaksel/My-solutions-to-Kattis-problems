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

bool good(ld d, vector<ld>&h,int n){
	ld pPosition = -1e18;
	fori(h.size()){
		if(abs(h[i]- pPosition>d)){	
			pPosition = h[i] + d;
			n--;
		}
		if (n < 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in(t){
		int n, m;
		cin >> n >> m;
		vector<ld>h;
		fori(m){
			ld a;
			cin >> a;
			h.push_back(a);
		}
		sort(all(h));
		ld fail=0, pass=1e18,ans= -1;
		fori(200){
			ld d = (pass + fail) / 2;
			if (good(d, h, n)) {
				pass = d;
				ans = d;
			}
			else{
				fail = d;
			}
		}
		cout << fixed << setprecision(1) << ans<<endl;
	}
}