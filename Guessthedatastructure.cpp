#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#include  <stack>;
#include <queue>;
#else
#include<bits/stdc++.h> //include this non portable headerfile 
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 

#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)

void disp(vector<int> a, vector<int> b, vector<int> c){
	fori(a.size())cout << a[i] << " ";
	cout << endl;
	fori(b.size())cout << b[i] << " ";
	cout << endl;
	fori(c.size())cout << c[i] << " ";
	cout << endl;
}
int main() {
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int t;
	label:
	while (cin >> t) {
		bool impossibe = 0;
		stack<int> my_stack;
		queue<int> q;
		priority_queue<int> pq;
		vector<int>stack_out, q_out, pq_out, true_out;
		fori(t) {
			int c, num;
			cin >> c >> num;
			if (c == 1) {
				my_stack.push(num);
				q.push(num);
				pq.push(num);
			}
			if (c == 2) {
				if (my_stack.size()) {
					stack_out.push_back(my_stack.top());
					q_out.push_back(q.front());
					pq_out.push_back(pq.top());
					true_out.push_back(num);
					my_stack.pop();
					q.pop();
					pq.pop();
				}
				else { impossibe = 1; }
			}
		}
		if(impossibe){
			cout << "impossible\n";
			impossibe = 0;
			goto label;
		}
		//disp(stack_out,q_out,pq_out);
		string ans = "impossible";
		int posibilities = 0;
		if (equal(all(stack_out), all(true_out))) {
			ans = "stack";
			posibilities++;
		}
		if (equal(all(q_out), all(true_out))) {
			posibilities++;
			ans = "queue";
		}
		if (equal(all(pq_out), all(true_out))) {
			posibilities++;
			ans = "priority queue";
		}
		if (posibilities > 1)
			cout << "not sure\n";
		else
			cout << ans << endl;
	}
}