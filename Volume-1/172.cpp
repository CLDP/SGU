#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 201;

int N, M;
bool x[MAXN][MAXN], z[MAXN], d[MAXN];


bool dfs(int a, bool b) {
    z[a] = true;
    d[a] = b;
    for (int i = 1; i <= N; ++i) {
        if (!x[a][i]) continue;
        if (z[i]) {
            if (d[i] != !b) return false;
            continue;
        }
        if (!z[i]) {
            if (!dfs(i, !b)) return false;
        }
    }
    return true;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        x[a][b] = x[b][a] = true;
    }
    
    for (int i = 1; i <= N; ++i) {
        if (z[i]) continue;
        if (!dfs(i, true)) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans += d[i];
    cout << ans << endl;
    for (int i = 1; i <= N; ++i) 
     if (d[i]) cout << i << " ";
    cout << endl;
    
    return 0;
}
