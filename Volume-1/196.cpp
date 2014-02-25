#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int d[MAXN];

int main() {
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        ++d[a];
        ++d[b];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans += d[i] * d[i];
    printf("%d\n", ans);
    
    return 0;
}
