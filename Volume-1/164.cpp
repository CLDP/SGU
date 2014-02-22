#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 201;
const int INF = 1000000000;

int f[MAXN][MAXN];


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int K = (M + 1) / 2, a;
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < N; ++j) {
         scanf("%d", &a);
         if (i == j) continue;
         f[i][j] = INF;
         if (a <= K) f[i][j] = 1;
     }
    
    for (int k = 0; k < N; ++k)
     for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) 
       f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    
    bool flag = true;
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < N; ++j) flag &= (f[i][j] <= 3);
    
    if (flag) {
        cout << K << endl;
        for (int i = 1; i <= K; ++i) cout << i << " ";
    } else {
        cout << M - K << endl;
        for (int i = K + 1; i <= M; ++i) cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
