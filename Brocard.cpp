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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	in(t){
		int n;
		ld ax, ay, bx, by, cx, cy;
		cin>>n>>ax>> ay>> bx>> by>> cx>> cy;
		//triangle sides
		ld ab = sqrt(pow(bx - ax, 2) + pow(by - ay,2));
		ld bc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
		ld ac = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
		//triangle angles
		ld cosa = (ab*ab + ac * ac - bc * bc) / (2 * ab*ac);
		ld A = acos(cosa);
		ld cosb = (ab*ab + bc * bc - ac * ac) / (2 * ab*bc);
		ld B = acos(cosb);
		ld cosc = (ac*ac + bc * bc - ab * ab) / (2 * ac*bc);
		ld C = acos(cosc);
		//brocard angle
		ld tanw = sin(A)*sin(B)*sin(C) / (1 + cos(A)*cos(B)*cos(C));
		ld w = atan(tanw);
				
		ld pi = acos(-1);
		ld al = pi - B;
		ld aP = ab * sin(B - w)/ sin(al);
		ld Px = ax + aP * cos(w);
		ld Py = ay + aP * sin(w);
		cout <<n<<" "<<setprecision(20)<< Px <<" "<< Py<<endl;
	}
}