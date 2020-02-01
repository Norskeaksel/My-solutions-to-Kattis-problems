#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
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
using vpl = vector<pll>;
using vpd = vector<pair<ld, ld>>;

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in() ll t; cin >> t; while(t--)
#define fin() ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

struct Car{
	ld value;
	int cost;
	int perkm;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in() {
		int cn, en;
		cin >> cn >> en;
		map<string, Car> name2car;
		map<string, ll>spy2cost;
		map<string, Car>spy2car;
		set<string> inconsistent;
		fori(cn){
			string n;
			Car a;
			cin >> n>>a.value>>a.cost>>a.perkm;
			name2car[n] = a;
		}
		fori(en){
			int time;
			string spy, type;
			cin >> time >> spy >> type;
			if (type == "p") {
				string name;
				cin >> name;
				if (spy2car.count(spy)) {
					inconsistent.insert(spy);
					spy2cost[spy] = 0;
				}
				else {
					Car car = name2car[name];
					spy2car[spy]=car;
					spy2cost[spy] += car.cost;
				}
			}
			else if(type=="r"){
				int km;
				cin >> km;
				if (spy2car.count(spy) == 0) {
					inconsistent.insert(spy);
					spy2cost[spy] = 0;
				}
				else {	
					Car car = spy2car[spy];
					spy2cost[spy] += km * car.perkm;
					spy2car.erase(spy);
				}
			}
			else{
				ld percent;
				cin >> percent;
				if (spy2car.count(spy) == 0) {
					inconsistent.insert(spy);
					spy2cost[spy] = 0;
				}
				else{
					Car car = spy2car[spy];
					spy2cost[spy] += ceil(car.value*percent / 1e2);
				}
			}
		}
		trav(spy2cost){
			cout << i.dx << " ";
			if (inconsistent.count(i.dx)||spy2car.count(i.dx))
				cout << "INCONSISTENT\n";
			else
				cout << i.dy << endl;
		}
	}
}