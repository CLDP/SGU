#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int INF = 100000000;

int x[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= m; ++j) cin >> x[i][j];
    
    for (int i = 1; i <= n; ++i) {
        f[0][i] = -INF;
        for (int j = 0; j <= m; ++j) f[i][j] = -INF;
    }
    
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= m; ++j) 
      for (int k = 0; k < j; ++k) 
       if (f[i-1][k] + x[i][j] > f[i][j]) {
           f[i][j] = f[i-1][k] + x[i][j];
           g[i][j] = k;
       }
    
    int ans = -INF, tmp;
    vector<int> anst;
    for (int i = 1; i <= m; ++i) 
     if (f[n][i] > ans) {
         ans = f[n][i];
         tmp = i;
     }
    
    for (int i = n; i >= 1; --i) {
        anst.push_back(tmp);
        tmp = g[i][tmp];
    }
    
    cout << ans << endl;
    cout << anst[anst.size() - 1];
    for (int i = anst.size() - 2; i >= 0; --i) cout << " " << anst[i];
    cout << endl;
    return 0;
}
