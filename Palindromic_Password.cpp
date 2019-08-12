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

bool isPalindrome(string nr) {
	int j = nr.size() - 1;
	fori(nr.size()) {
		if (nr[i] != nr[j])
			return false;
		j--;
	}
	return true;
}

int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n;
	cin >> n;
	while (n--) {
		int p, a, b;
		cin >> p;
		a = p;
		b = p;
		while (isPalindrome(to_string(a)) == 0 && isPalindrome(to_string(b)) == 0) {
			a++;
			b--;
		}
		if (isPalindrome(to_string(b))&&b>=100000)
			cout << b << endl;
		else
			cout << a << endl;
	}
}
/*while(isPalindrome(to_string(a))==0){
	a++;
}
while(isPalindrome(to_string(b)) == 0)
	b--;
string str = to_string(p);
int j = str.size() - 1;
fori(str.size()/2){
	str[j] = str[i];
	j--;
}
int mir = stoi(str);
int num[3] = { abs(p - mir),p - b,a - p };
int can[3] = { mir,b,a };
//cout << "Max element Index: " << max_element(num, num+ 3) - num;
cout << can[min_element(num, num + 3)-num]<<endl;
if (isPalindrome(to_string(b)))
	cout << b<<endl;
else
	cout << a<<endl;*/