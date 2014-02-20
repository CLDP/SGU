#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1000000000;

int N, bwx, bwy, dist;


bool cross(int l1, int r1, int l2, int r2) {
    return l2 <= r1 && l1 <= r2;
}

bool inside(int y, int l, int r) {
    return l <= y && y <= r;
}

int check(int sx, int sy, int ex, int ey, int step) {
    int dir = ex > sx ? 1 : -1;
    for (int i = 1; i <= step; ++i) {
       int l = max(1, max(sy - i, ey - (dist - i)));
       int r = min(N, min(sy + i, ey + (dist - i)));
       int x = sx + dir * i;
       if (((x == bwx - i || x == bwx + i) && cross(l, r, bwy - i, bwy + i))
        || (abs(bwx - x) < i && (inside(bwy - i, l, r) || inside(bwy + i, l, r)))) return i;
    }
    return INF;
}


int main() {
    int bx, by, wx, wy;
    cin >> N >> bx >> by >> wx >> wy >> bwx >> bwy;
    if (abs(bx - wx) < abs(by - wy)) {
        swap(bx, by);
        swap(wx, wy);
        swap(bwx, bwy);
    }
    dist = abs(bx - wx);
    int ans = min(check(bx, by, wx, wy, dist / 2 - 1), check(wx, wy, bx, by, dist / 2 - 1));
    if (ans != INF) 
        cout << "YES" << endl << ans << endl;
    else 
        cout << "NO" << endl << dist - 1 << endl;
    
    return 0;
}
