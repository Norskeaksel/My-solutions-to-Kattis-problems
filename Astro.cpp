#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 
#include <smmintrin.h>

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;

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
string min2hour(ll final_hour){
    ll h = (final_hour / 60) % 24;
    string a;
        if (h < 10)
            a += "0";
    a+=to_string(h) + ":";
    ll rest = final_hour % 60;
    if (rest == 0)
        a += "00";
    else if (rest < 10)
        a += "0" + to_string(rest);
    else
        a += to_string(rest);
    return a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
    freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
    ll x;
    vector<ll> ip(4, 0);
    string str;
    for (ll i = 0; i < 4; i++) {
        cin >> str;
        string a = str.substr(0, 2);
        ip[i] += stoi(a) * 60;
        a = str.substr(3, 2);
        ip[i] += stoi(a);
    }
    ll star1time = ip[0], star2time = ip[1], frec1 = ip[2], frec2 = ip[3];
    ll currentDay = 0;
    string nr2day[7]={ "Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    fori(1e4){
        //cout << min2hour(star1time) << " " << min2hour(star2time) <<" "<< nr2day[currentDay]<< endl;
        if(star1time== star2time){
            ll day = (star1time / 1440)%7;
            cout << nr2day[day] << endl<< min2hour(star1time);
            exit(0);
        }
        else if(star1time< star2time){
            star1time += frec1;
        }
        else if(star1time > star2time){
            star2time += frec2;
        }
    }
    cout << "Never\n";
}