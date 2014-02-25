#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 310;

struct point {
    double x, y;
};

struct segment {
    point a, b;
    char c;
};

segment x[MAXN];

bool cal_cross(point a, point b, point c, point d, point &ans) {
    double delta = (b.x - a.x) * (c.y - d.y) - (d.x - c.x) * (a.y - b.y);
    if (abs(delta) < 1e-8) return false;
    
    ans.x = ((c.y * d.x - c.x * d.y) * (b.x - a.x) - (a.y * b.x - a.x * b.y) * (d.x - c.x)) / delta;
    ans.y = ((a.y * b.x - a.x * b.y) * (c.y - d.y) - (c.y * d.x - c.x * d.y) * (a.y - b.y)) / delta;
    return true;
}

int sign(double a) {
    if (fabs(a) < 1e-8) return 0;
    return a > 0 ? 1 : -1;
}

double caly(int a, double X) {
    if (X < x[a].a.x || x[a].b.x < X) return 1e6;
    return x[a].a.y + (x[a].b.y - x[a].a.y) / (x[a].b.x - x[a].a.x) * (X - x[a].a.x);
}


int main() {
    int N;
    cin >> N;
    vector<double> T;
    for (int i = 0; i < N; ++i) {
        cin >> x[i].a.x >> x[i].a.y >> x[i].b.x >> x[i].b.y >> x[i].c;
        if (x[i].a.x > x[i].b.x) {
            swap(x[i].a.x, x[i].b.x);
            swap(x[i].a.y, x[i].b.y);
        }
        T.push_back(x[i].a.x);
        T.push_back(x[i].b.x);
    }
    
    for (int i = 0; i < N; ++i) {
        if (fabs(x[i].a.x - x[i].b.x) < 1e-8) continue;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (x[i].b.x <= x[j].a.x) continue;
            if (x[j].b.x <= x[i].a.x) continue;
            if (fabs(x[j].a.x - x[j].b.x) < 1e-8) continue;
            point P;
            if (!cal_cross(x[i].a, x[i].b, x[j].a, x[j].b, P)) continue;
            if (P.x <= x[i].a.x) continue;
            if (x[i].b.x <= P.x) continue;
            T.push_back(P.x);
        }
    }
    sort(T.begin(), T.end());
    
    double ansR, ansG, ansB;
    ansR = ansG = ansB = 0;
    for (int i = 1; i < T.size(); ++i) {
        double T1 = T[i - 1], T2 = T[i];
        if (T2 - T1 < 1e-8) continue;
        int L = -1;
        for (int j = 0; j < N; ++j) {
            if (x[j].b.x <= T1) continue;
            if (T2 <= x[j].a.x) continue;
            if (L == -1 || sign(caly(j, T1) - caly(L, T1)) + sign(caly(j, T2) - caly(L, T2)) < 0) L = j;
        }
        if (L == -1) continue;
        switch (x[L].c) {
            case 'R' : ansR += T2 - T1; break;
            case 'G' : ansG += T2 - T1; break;
            case 'B' : ansB += T2 - T1; break;
        }
    }
    printf("R %.2lf\n", ansR);
    printf("G %.2lf\n", ansG);
    printf("B %.2lf\n", ansB);
    
    return 0;
}
