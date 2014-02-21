#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50010;

struct node {
    int a, b, c;
    bool operator < (node const &B) const {
        return a < B.a;
    }
};

int l[MAXN], r[MAXN], f[MAXN], k[MAXN], C[MAXN], B[MAXN];


int rotate(int b) {
    int a = f[b], c = l[b];
    r[a] = c;
    l[b] = a;
    if (a == l[f[a]]) l[f[a]] = b; else r[f[a]] = b;
    f[b] = f[a];
    f[a] = b;
    f[c] = a;
    return 0;
}


int main() {
    int N;
    scanf("%d", &N);
    vector<node> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i].a >> x[i].b;
        x[i].c = i + 1;
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < N; ++i) {
        C[i + 1] = x[i].c;
        B[x[i].c] = i + 1;
    }
    
    int temp = 1;
    k[1] = x[0].b;
    for (int i = 1; i < N; ++i) {
        r[temp] = i + 1;
        f[i + 1] = temp;
        k[i + 1] = x[i].b;
        while (f[i + 1] != 0 && k[i + 1] < k[f[i + 1]]) rotate(i + 1);
        temp = i + 1;
    }
    
    printf("YES\n");
    for (int i = 1; i <= N; ++i) printf("%d %d %d\n", C[f[B[i]]], C[l[B[i]]], C[r[B[i]]]);
    
    return 0;
}
