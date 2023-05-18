#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h>
using namespace std;
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;
using vpd = vector<pair<ld, ld>>;
using vs = vector<string>;

#define all(v) (v).begin(),(v).end()
#define fori(n) for (ll i=0;i<n;i++)
#define in() ll t; cin >> t; while(t--)
#define trav(v) for(auto &i:v)

int find(int idx, vll& friends) {
	vll path;
	int c = 0;
	while (friends[idx] >= 0) {
		path.push_back(idx);
		idx = friends[idx];
		//c++;
		//if (c > 111000)
			//abort();// test for infinite loop
	}
	trav(path) {
		friends[i] = idx;
	}
	return idx;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in() {
		vll friends;
		unordered_map<string, int> n2i;
		int idx = 0;
		in() {
			string name1, name2;
			cin >> name1 >> name2;
			if (n2i.count(name1) == 0) {
				n2i[name1] = idx++;
				friends.push_back(-1);
			}
			if (n2i.count(name2) == 0) {
				n2i[name2] = idx++;
				friends.push_back(-1);
			}
			int idx1 = n2i[name1], idx2 = n2i[name2];
			int root1 = find(idx1, friends);
			int root2 = find(idx2, friends);
			if (root1 != root2) {
				friends[root2] += friends[root1];
				friends[root1] = root2;
			}
			int ans= friends[root2];
			cout << abs(ans) << endl;
		}
	}
}