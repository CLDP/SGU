#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXM = 100010;

struct node {
    int b, next;
};


int d[MAXN];
node l[MAXM * 2];
bool z[MAXM], cz[MAXN];
int ans[MAXN], cnt = 0;
int x[MAXN];


int dfs(int a, bool flag) {
    if (d[a] == 2) {
        int c = x[a];
        for ( ; c != -1; c = l[c].next) {
            int b = l[c].b;
            if (cz[b]) continue;
            if (z[c / 2]) continue;
            z[c / 2] = true;
            x[a] = l[c].next;
            dfs(b, false);
            ans[cnt++] = b;
            cz[b] = true;
        }
    } else {
        int c = x[a];
        for ( ; c != -1; c = l[c].next) {
            int b = l[c].b;
            if (cz[b]) continue;
            if (z[c / 2]) continue;
            if (flag && d[b] != 2) continue;
            if (!flag && d[b] == 2) continue;
            z[c / 2] = true;
            x[a] = l[c].next;
            dfs(b, !flag);
            if (flag) {
                ans[cnt++] = b;
                ans[cnt++] = a;
                cz[a] = cz[b] = true;
            }
        }
    }
    return 0;
}


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) x[i] = -1;
    for (int i = 0; i < M; ++i) {
        int pos = 2 * i, a, b;
        scanf("%d%d", &a, &b);
        l[pos].b = b;
        l[pos].next = x[a];
        x[a] = pos;
        ++pos;
        l[pos].b = a;
        l[pos].next = x[b];
        x[b] = pos;
        ++d[a];
        ++d[b];
    }
    
    for (int i = 1; i <= N; ++i) {
        if (d[i] != 2 && d[i] % 2 == 1) {
            printf("-1\n");
            return 0;
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        if (d[i] != 2) continue;
        dfs(i, false);
        break;
    }
    
    if (cnt != N) {
        printf("-1\n");
    } else {
        for (int i = 0; i < N; ++i) {
            printf("%d", ans[i]);
            if (i == N - 1) printf("\n"); else printf(" ");
        }
    }

    return 0;
}
