#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct rect {
    int x1, y1, x2, y2, color;
};

vector<rect> x;


bool get_boundary(int x1, int x2, int x3, int x4, int &k1, int &k2) {
    k1 = max(x1, x3);
    k2 = min(x2, x4);
    if (k1 >= k2) return false;
    return true;
}

int add_one(int x1, int y1, int x2, int y2, int color) {
    rect p;
    p.x1 = x1;
    p.y1 = y1;
    p.x2 = x2;
    p.y2 = y2;
    p.color = color;
    x.push_back(p);
    return 0;
}

int add(int a, int b, int c, int d, int color) {
    int j = 0, len = x.size();
    
    while (j < len) {
        int k1, k2, k3, k4;
        if (!get_boundary(x[j].x1, x[j].x2, a, c, k1, k2)) {
            ++j;
            continue;
        }
        
        if (!get_boundary(x[j].y1, x[j].y2, b, d, k3, k4)) {
            ++j;
            continue;
        }
        
        if (x[j].x1 < k1) add_one(x[j].x1, x[j].y1, k1, x[j].y2, x[j].color);
        if (k2 < x[j].x2) add_one(k2, x[j].y1, x[j].x2, x[j].y2, x[j].color);
        if (x[j].y1 < k3) add_one(k1, x[j].y1, k2, k3, x[j].color);
        if (k4 < x[j].y2) add_one(k1, k4, k2, x[j].y2, x[j].color);
        x.erase(x.begin() + j);
        --len;
    }
    
    add_one(a, b, c, d, color);
}


int main() {
    int N, M;
    scanf("%d%d", &N, &M); 
    add(0, 0, N, N, 0);
    for (int i = 0; i < M; ++i) {
        int a, b, c, d;
        char e;
        scanf("%d%d%d%d %c", &a, &b, &c, &d, &e);
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        add(a - 1, b - 1, c, d, e == 'b');
    }
    
    int ans = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i].color == 1) continue;
        ans += (x[i].y2 - x[i].y1) * (x[i].x2 - x[i].x1);
    }
    cout << ans << endl;
    
    return 0;
}
