#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		double v, o, x, h1, h2,t=0, g = 9.81;
		cin >> v >> o >> x >> h1 >> h2;
		o *= acos(-1) / 180;
		h1 = h1 + 1;
		h2 = h2 - 1;
		double y =0;
		//cout << 19 * 0.09*sin(o) - g*0.09*0.09/2;
		while (v*t*cos(o)<x&&y>=-10){
			//cout << v * t*sin(o) - 1 / 2 * g*t*t <<endl;
			t += 0.003;
			y = v * t*sin(o) -g*t*t / 2;
		}
		
		if (y > h1&&y < h2)
			cout << "Safe\n";
		else
			cout << "Not safe\n";
	}
}