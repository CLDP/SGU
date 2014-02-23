#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1002;
const int INF = 1000000000;

int x[MAXN][MAXN], d[MAXN][MAXN], f[MAXN][MAXN];


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
     for (int j = 1; j <= M; ++j) scanf("%d", &x[i][j]);
    
    for (int i = 0; i <= N + 1; ++i)
     for (int j = 0; j <= M + 1; ++j) f[i][j] = d[i][j] = INF;
    
    for (int i = N; i >= 1; --i)
     for (int j = 1; j <= M; ++j) d[i][j] = min(d[i + 1][j], x[i][j]);
    
    for (int i = 1; i <= N; ++i)
     for (int j = M; j >= 1; --j) f[i][j] = min(min(f[i - 1][j + 1], f[i][j + 1]), d[i][j]);
    
    for (int i = 1; i <= N; ++i)
     for (int j = 1; j <= M; ++j) {
         printf("%d", f[i][j]);
         if (j == M) printf("\n"); else printf(" ");
     }
    
    return 0;
}
