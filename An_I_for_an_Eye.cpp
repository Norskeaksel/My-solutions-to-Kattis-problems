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
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in(t) ll t; cin >> t; while(t--)
#define fin(n) ll n; cin >> n; fori(n)
#define trav(v) for(auto &e:v)
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)

template <class T>
void ipb(vector<T>&v) {
	T a;
	cin >> a;
	v.pb(a);
}

vector<string> a = { "four", "and", "are", "bea", "bee", "eye", "for", "one", "owe", "sea", "see", "too", "two", "why", "won", "you", "at", "be", "oh", "to", "Four", "And", "Are", "Bea", "Bee", "Eye", "For", "One", "Owe", "Sea", "See", "Too", "Two", "Why", "Won", "You", "At", "Be", "Oh", "To" };
vector<string> b = { "4", "&", "r", "b", "b", "i", "4", "1", "o", "c", "c", "2", "2", "y", "1", "u", "@", "b", "o", "2", "4", "&", "R", "B", "B", "I", "4", "1", "O", "C", "C", "2", "2", "Y", "1", "U", "@", "B", "O", "2" };

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	while (getline(cin, str)) {
		fori(sz(str)) {
			forj(sz(a)) {
				ll s = sz(a[j]);
				if (i + s <= sz(str)) {
					string check = str.substr(i, s);
					if (check == a[j]) {
						str.replace(i, s, b[j]);
						i += sz(b[j]);
						//cout << str << endl;
					}
				}	
			}
		}
		cout << str << endl;
	}
}

/*#if defined _MSC_VER //if using Visual Studio
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


void findAndReplaceFirst(string & data, string toSearch, string replaceStr) {
	size_t pos = data.find(toSearch);// Get the first occurrence
	if (pos == std::string::npos);
	else data.replace(pos, toSearch.length(), replaceStr);
}
vector<string> strsplit(string text) {
	istringstream iss(text);
	vector<string> results((istream_iterator<string>(iss)),
		istream_iterator<string>());
	return results;
}
vector<string> a = { "four", "and", "are", "bea", "bee", "eye", "for", "one", "owe", "sea", "see", "too", "two", "why", "won", "you", "at", "be", "oh", "to", "Four", "And", "Are", "Bea", "Bee", "Eye", "For", "One", "Owe", "Sea", "See", "Too", "Two", "Why", "Won", "You", "At", "Be", "Oh", "To" };
vector<string> c = { "4", "&", "r", "b", "b", "i", "4", "1", "o", "c", "c", "2", "2", "y", "1", "u", "@", "b", "o", "2", "4", "&", "R", "B", "B", "I", "4", "1", "O", "C", "C", "2", "2", "Y", "1", "U", "@", "B", "O", "2" };

vector<string> b = { "56789���", "56789���", "56789���", "56789���", "56789���", "56789���", "5678�9��", "5678�9��", "5678��9�", "5678���9", "5678���9", "5678��9�", "5678��9�", "5678���9", "5678�9��", "5678�9��", "5678��9�", "5678���9", "5678���9", "5678��9�", "5678���9", "5678��9�", "5678�9��", "5678�9��", "56798���", "56798���", "56798���", "56798���", "56798���", "56798���", "5679�8��", "5679�8��", "5679��8�", "5679���8", "5679���8", "5679��8�", "5679��8�", "5679���8", "5679�8��", "5679�8��", };
int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	fork(t) {
		getline(cin, str);
		vector<string> s = strsplit(str);
		for (auto &i : s) {
				forj(a.size()) {
					findAndReplaceFirst(i, a[j], b[j]);
				}
				forj(a.size()){
					findAndReplaceFirst(i, b[j], c[j]);
				}
		}
		for (auto i : s)
			cout << i << " ";
		cout << endl;
	}
}*/