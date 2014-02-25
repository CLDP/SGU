#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct node {
    int a, b, c;
    bool operator < (node const &B) const {
        if (a != B.a) return a < B.a;
        return b > B.b;
    }
};

node x[MAXN];
int p[MAXN], q[MAXN], f[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &x[i].a, &x[i].b);
        x[i].c = i + 1;
    }
    sort(x, x + N);
    
    int ans = 1;
    p[1] = x[0].b, q[1] = 1;
    for (int i = 1; i < N; ++i) {
        if (p[1] == x[i].b || p[ans] == x[i].b) continue;
        if (p[1] > x[i].b) {
            p[1] = x[i].b;
            q[1] = i + 1;
            continue;
        }
        if (p[ans] < x[i].b) {
            p[++ans] = x[i].b;
            q[ans] = i + 1;
            f[i + 1] = q[ans - 1];
            continue;
        }
        int l = 1, r = ans + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (p[mid] < x[i].b) l = mid; else r = mid;
        } 
        if (p[l + 1] > x[i].b) {
            p[l + 1] = x[i].b;
            q[l + 1] = i + 1;
            f[i + 1] = q[l];
        }
    }
    
    printf("%d\n", ans);
    vector<int> ansT;
    ans = q[ans];
    while (ans > 0) {
        ansT.push_back(x[ans - 1].c);
        ans = f[ans];
    }
    sort(ansT.begin(), ansT.end());
    for (int i = 0; i < ansT.size(); ++i) cout << ansT[i] << " ";
    cout << endl;
    
    return 0;
}
