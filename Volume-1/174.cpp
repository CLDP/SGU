#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 400010;

int M, d[MAXN], f[MAXN];
map<pair<int, int>, int> C; 

int find(int a) {
    if (a != f[a]) f[a] = find(f[a]);
    return f[a];
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (d[a] > d[b]) f[b] = f[a]; else f[a] = f[b];
    d[a] += d[b];
    d[b] = d[a];
    return true;
}


int main() {
    int N, a, b, p, q;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &a, &b, &p, &q);
        if (C.find(make_pair(a, b)) == C.end()) {
            C[make_pair(a, b)] = ++M;
            d[M] = 1;
            f[M] = M;
        }
        if (C.find(make_pair(p, q)) == C.end()) {
            C[make_pair(p, q)] = ++M;
            d[M] = 1;
            f[M] = M;
        }
        int A = C[make_pair(a, b)], B = C[make_pair(p, q)];
        if (!Union(A, B)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
