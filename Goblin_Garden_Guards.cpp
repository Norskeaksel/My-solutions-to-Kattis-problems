#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;

/*struct Circle {
    ll cx;
    ll cy;
    ll cr;
};*/

bool isInside(ll px, ll py, ll cx, ll cy, ll cr) {
    //ll cx = c.cx, cy = c.cy, cr = c.cr;
    return pow(px - cx, 2) + pow(py - cy, 2) <= cr * cr;
}
int grid[12345][12345];
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>>goblins;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        goblins.push_back({ x,y });
    }
    cin >> n;
    set<pair<ll, ll>>hitSquares;
    for (int k = 0; k < n; k++) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int dx = max(x - r,0); dx <= min(x + r,10000); dx++) {
            for (int dy = max(y - r,0); dy <= min(y + r,10000); dy++) {
                if (isInside(dx, dy, x, y, r))
                    grid[dx][dy]=1;
            }
        }
        /*for (int i = y - r; i < y + r; i++) {
    for (int j = x; (j - x)*(j - x) + (i - y)*(i - y) <= r * r; j--) {
        hitSquares.insert({ i,j });
    }
    for (int j = x + 1; (j - x)*(j - x) + (i - y)*(i - y) <= r * r; j++) {
        hitSquares.insert({ i,j });
    }
}*/
    }
    int nr = goblins.size();
    for (auto i : goblins) {
        if (grid[i.first][i.second])
            nr--;
    }
    cout << nr << endl;
}
