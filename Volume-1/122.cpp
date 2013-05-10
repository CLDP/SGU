#include <cmath>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

int n, m, fm;
bool xx[MAXN][MAXN];
bool z[MAXN];
int ans[MAXN], f[MAXN];
char s[3900];


int dfs(int a, bool time) {
    z[a] = true;
    if (!time) 
        ans[++m] = a;
    else
        f[fm++] = a;
        
    for (int i = 1; i <= n; ++i) 
     if (xx[a][i] && !z[i]) {
         dfs(i, time);
         break;
     }
    
    return 0;
}



int main() {
    scanf("%d\n", &n);
    int a;
    for (int i = 1; i <= n; ++i) {
        gets(s);
        int len = strlen(s), a = 0;
        for (int j = 0; j < len; ++j)
         if (s[j] == ' ') {
             xx[i][a] = true;
             a = 0;
         } else {
             a = a * 10 + (s[j] - '0');
         }
         xx[i][a] = true;
    }
    
    // Then check whether it can grow further
    dfs((1 + n) / 2, false);
    dfs((1 + n) / 2, true);
    --fm;
    for (int i = m; i >= 1; --i) ans[i+fm] = ans[i];
    for (int i = 1; i <= fm; ++i) ans[i] = f[fm - i + 1];
    m += fm;
    
    while (true) {
        if (!xx[ans[1]][ans[m]]) {
            for (int i = 2; i < m; ++i) 
             if (xx[ans[1]][ans[i]] && xx[ans[i-1]][ans[m]]) 
              for (int j = i, k = m; j < k; ++j, --k) swap(ans[j], ans[k]);
        }
        
        if (m == n) break;
        
        bool flag = false;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) 
             if (xx[ans[i]][j] && !z[j]) {
                 z[j] = true;
                 flag = true;
                 f[1] = j;
                 for (int k = i; k <= m; ++k) f[k-i+2] = ans[k];
                 for (int k = 1; k < i; ++k) f[m-i+2+k] = ans[k];
                 ++m;
                 for (int k = 1; k <= m; ++k) ans[k] = f[k];
                 break;
             }
             
            if (flag) break;
        }
    }
    
    int j = 1;
    while (ans[j] != 1) ++j;
    for (int i = j; i <= n; ++i) printf("%d ", ans[i]);
    for (int i = 1; i < j; ++i)  printf("%d ", ans[i]);
    printf("1\n");
    
    return 0;
}
