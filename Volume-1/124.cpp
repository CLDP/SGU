#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int x1, y1, x2, y2;
};

vector<node> p;


int main() {
    int n;
    node q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &q.x1, &q.y1, &q.x2, &q.y2);
        p.push_back(q);
    }
    
    double a, b;
    cin >> a >> b;
    
    for (int i = 0; i < n; ++i) {
        if ((p[i].x1 - a) * (p[i].y1 - p[i].y2) == (p[i].y1 - b) * (p[i].x1 - p[i].x2)) {
            if (a < p[i].x1 && a < p[i].x2) continue;
            if (a > p[i].x1 && a > p[i].x2) continue;
            if (b < p[i].y1 && b < p[i].y2) continue;
            if (b > p[i].y1 && b > p[i].y2) continue;
            cout << "BORDER" << endl;
            return 0;
        }
    }
    
    
    int ans = 0;
    a = a + 0.00001;
    b = b + 0.00001;
    for (int i = 0; i < n; ++i) {
        if (p[i].x1 == p[i].x2) continue;
        if (p[i].y1 == p[i].y2) {
            if (p[i].y1 < b) continue;
            if (p[i].x1 <= a && a <= p[i].x2) {
                ++ans;
                continue;
            }
            if (p[i].x2 <= a && a <= p[i].x1) {
                ++ans;
                continue;
            }
            continue;
        }
        
        double yy = - 1.0 * (p[i].x1 - a) * (p[i].y1 - p[i].y2) / (p[i].x1 - p[i].x2) + p[i].y1;
        if (yy < b) continue;
        
        if (p[i].y1 <= yy && yy <= p[i].y2) {
            ++ans;
            continue;
        }
        if (p[i].y2 <= yy && yy <= p[i].y1) {
            ++ans;
            continue;
        }
        
    }
    
    if (ans & 1) {
        cout << "INSIDE" << endl;
    } else {
        cout << "OUTSIDE" << endl;
    }
    
    return 0;
}
