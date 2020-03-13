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
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

struct Card{
	ll value;
	ll trueIndex;
	ll whichStack;
	ll whereInStack;
	ll parentCard;
};
struct Stack{
	vector<Card> deck;
	Card topCard;
};
bool operator<(Stack a,Stack b){
	return a.topCard.value < b.topCard.value;
}

void longestIncreasingSubsequence(vector<Stack> &board){
	vll ansIndex;
	ll whereInStack = board[board.size() - 1].deck.size()-1;
	for(ll i = ll(board.size())-1;i>=0;i--){
		ansIndex.pb(board[i].deck[whereInStack].trueIndex);
		whereInStack = board[i].deck[whereInStack].parentCard;
	}
	cout << ansIndex.size()<<endl;
	for (ll i = ansIndex.size() - 1; i >= 0; i--) {
		cout << ansIndex[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	while(cin>>n){
		vector<Stack> board;
		fori(n) {
			ll val;
			cin >> val;
			Stack next;
			Card newCard={val,i};
			next.topCard = newCard;
			auto it=lower_bound(all(board), next);
			newCard.whichStack = distance(board.begin(), it);
			if (board.size() == newCard.whichStack) {//if we need to add a stack
				if(board.size())
					newCard.parentCard = board[newCard.whichStack - 1].deck.size()-1;//Point to the top card of the stack to the left
				newCard.whereInStack = 0;
				next.deck.pb(newCard);
				board.pb(next);
			}
			else{//place in current stack
				if(newCard.whichStack)
					newCard.parentCard = board[newCard.whichStack-1].deck.size()-1;//top card of left stack
				newCard.whereInStack = board[newCard.whichStack].deck.size();
				board[newCard.whichStack].deck.pb(newCard);
				board[newCard.whichStack].topCard = newCard;
			}
		}
		longestIncreasingSubsequence(board);
	}
}