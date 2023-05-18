#include <iostream>
using namespace std;
using ll = long long;
#define in() ll t; cin >> t; while(t--)

ll modInverse(ll a, ll m) {//gcd(a,m)==1
	ll m0 = m;
	ll y = 0, x = 1;
	if (m == 1)
		return 1;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in() {
		ll a, n, b, m;
		cin >> a >> n >> b >> m;
		ll k = n * m;
		//ll n1 = k / n;
		//ll n2 = k / m;
		ll inv1 = modInverse(m, n);
		ll inv2 = modInverse(n, m);
		ll x = (inv1*a%n*m%k + inv2*b%m*n%k) % k;
		//cout << x << " " << k << endl;
	}
	cout << (-1 % 2);
}
