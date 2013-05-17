#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 72;
const int MAXS = 1 << 7;
const int INF = 1000000000;

int n, m, s, l, r;
int x[MAXN];
int f[2][MAXS][MAXS];


int dfs(int a, int b, int c, int i, int j, int d) {
    if (i >= s) {
        f[r][b ^ s][c] = min(f[r][b ^ s][c], d);
        return 0;
    }
    if (b & i) {
        dfs(a, b, c, i << 1, 0, d);
    } else {
        if ((a & i) && j < 1) dfs(a, b, c, i << 1, j + 1, d);
        if ((c & i) == 0) dfs(a, b | i, c | i, i << 1, 0, d + 1);
        if ((b & (i << 1)) == 0) dfs(a, b | i | (i << 1), c, i << 2, 0, d + 1);
    }
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        string p;
        cin >> p;
        for (int j = 0; j < n; ++j) {
            x[i] <<= 1;
            x[i] |= (p[j] == '*');
        }
    }
    
    s = 1 << n;
    l = 0, r = 1;
    memset(f, 1, sizeof(f));
    f[l][s - 1][s - 1] = 0;
    x[m] = x[m + 1] = s - 1;
    for (int i = 0; i <= m + 1; ++i) {
        for (int j = 0; j < s; ++j)
         for (int k = 0; k < s; ++k) f[r][j][k] = INF;
          
        for (int j = 0; j < s; ++j)
         for (int k = 0; k < s; ++k)
          if (f[l][j][k] < INF) dfs(j | s, k | s, x[i], 1, 0, f[l][j][k]);
          
        l ^= 1;
        r ^= 1;
    }
    
    cout << f[l][s - 1][s - 1] << endl;
    
    return 0;
}
