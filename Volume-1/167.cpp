#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

struct node {
    int j1, j2, k, t;
};


int N, M, K;
int x[15][15], y[15][16];
int f[15][15][15][226][4];
node g[15][15][15][226][4];
bool z[15][15];


int main() {
    cin >> N >> M >> K;
    if (K == 0) {
        cout << "Oil : 0" << endl;
        return 0;
    }
    
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < M; ++j) {
         cin >> x[i][j];
         y[i][j + 1] = y[i][j] + x[i][j];
     }
    
    memset(f, -1, sizeof(f));
    for (int j1 = 0; j1 < M; ++j1) {
        int temp = 0, num = 0;
        for (int j2 = j1; j2 < M; ++j2) {
            temp += x[0][j2];
            ++num;
            f[0][j1][j2][num][0] = f[0][j1][j2][num][1] = 
            f[0][j1][j2][num][2] = f[0][j1][j2][num][3] = temp;
        }
    }
    
    for (int i = 0; i < N - 1; ++i) {
        for (int j1 = 0; j1 < M; ++j1) {
            int temp = 0, num = 0;
            for (int j2 = j1; j2 < M; ++j2) {
                temp += x[i + 1][j2];
                ++num;
                f[i + 1][j1][j2][num][0] = f[i + 1][j1][j2][num][1] = 
                f[i + 1][j1][j2][num][2] = f[i + 1][j1][j2][num][3] = temp;
            }
        }
    
        for (int j1 = 0; j1 < M; ++j1)
         for (int j2 = j1; j2 < M; ++j2) 
          for (int k = 0; k <= K; ++k) {
              if (f[i][j1][j2][k][0] != -1) {
                  int &prev = f[i][j1][j2][k][0];
                  for (int j3 = j1; j3 >= 0; --j3) 
                   for (int j4 = j2; j4 < M; ++j4) {
                       if (k + j4 - j3 + 1 > K) continue;
                       int &f0 = f[i + 1][j3][j4][k + j4 - j3 + 1][0];
                       int &f1 = f[i + 1][j3][j4][k + j4 - j3 + 1][1];
                       int &f2 = f[i + 1][j3][j4][k + j4 - j3 + 1][2];
                       int &f3 = f[i + 1][j3][j4][k + j4 - j3 + 1][3];
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f0) {
                           f0 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g0 = g[i + 1][j3][j4][k + j4 - j3 + 1][0];
                           g0.j1 = j1, g0.j2 = j2, g0.k = k, g0.t = 0;
                       }
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f1) {
                           f1 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g1 = g[i + 1][j3][j4][k + j4 - j3 + 1][1];
                           g1.j1 = j1, g1.j2 = j2, g1.k = k, g1.t = 0;
                       }
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f2) {
                           f2 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g2 = g[i + 1][j3][j4][k + j4 - j3 + 1][2];
                           g2.j1 = j1, g2.j2 = j2, g2.k = k, g2.t = 0;
                       }
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f3) {
                           f3 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g3 = g[i + 1][j3][j4][k + j4 - j3 + 1][3];
                           g3.j1 = j1, g3.j2 = j2, g3.k = k, g3.t = 0;
                       }
                   }
              }
              
              if (f[i][j1][j2][k][1] != -1) {
                  int &prev = f[i][j1][j2][k][1];
                  for (int j3 = j1; j3 >= 0; --j3) 
                   for (int j4 = j2; j4 >= j1; --j4) {
                       if (k + j4 - j3 + 1 > K) continue;
                       int &f1 = f[i + 1][j3][j4][k + j4 - j3 + 1][1];
                       int &f3 = f[i + 1][j3][j4][k + j4 - j3 + 1][3];
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f1) {
                           f1 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g1 = g[i + 1][j3][j4][k + j4 - j3 + 1][1];
                           g1.j1 = j1, g1.j2 = j2, g1.k = k, g1.t = 1;
                       }
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f3) {
                           f3 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g3 = g[i + 1][j3][j4][k + j4 - j3 + 1][3];
                           g3.j1 = j1, g3.j2 = j2, g3.k = k, g3.t = 1;
                       }
                   }
              }
              
              if (f[i][j1][j2][k][2] != -1) {
                  int &prev = f[i][j1][j2][k][2];
                  for (int j3 = j1; j3 <= j2; ++j3) 
                   for (int j4 = j2; j4 < M; ++j4) {
                       if (k + j4 - j3 + 1 > K) continue;
                       int &f2 = f[i + 1][j3][j4][k + j4 - j3 + 1][2];
                       int &f3 = f[i + 1][j3][j4][k + j4 - j3 + 1][3];
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f2) {
                           f2 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g2 = g[i + 1][j3][j4][k + j4 - j3 + 1][2];
                           g2.j1 = j1, g2.j2 = j2, g2.k = k, g2.t = 2;
                       }
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f3) {
                           f3 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g3 = g[i + 1][j3][j4][k + j4 - j3 + 1][3];
                           g3.j1 = j1, g3.j2 = j2, g3.k = k, g3.t = 2;
                       }
                   }
              }
              
              if (f[i][j1][j2][k][3] != -1) {
                  int &prev = f[i][j1][j2][k][3];
                  for (int j3 = j1; j3 <= j2; ++j3) 
                   for (int j4 = j2; j4 >= j3; --j4) {
                       if (k + j4 - j3 + 1 > K) continue;
                       int &f3 = f[i + 1][j3][j4][k + j4 - j3 + 1][3];
                       if (prev + y[i + 1][j4 + 1] - y[i + 1][j3] > f3) {
                           f3 = prev + y[i + 1][j4 + 1] - y[i + 1][j3];
                           node &g3 = g[i + 1][j3][j4][k + j4 - j3 + 1][3];
                           g3.j1 = j1, g3.j2 = j2, g3.k = k, g3.t = 3;
                       }
                   }
              }
          }
    }
    
    int ans = -1, i0;
    node ansT;
    for (int i = 0; i < N; ++i)
     for (int j1 = 0; j1 < M; ++j1)
      for (int j2 = j1; j2 < M; ++j2) 
       for (int l = 0; l < 4; ++l) 
        if (f[i][j1][j2][K][l] > ans) {
            ans = f[i][j1][j2][K][l];
            i0 = i;
            ansT.j1 = j1;
            ansT.j2 = j2;
            ansT.k = K;
            ansT.t = l;
        }
    
    while (K > 0) {
        for (int j = ansT.j1; j <= ansT.j2; ++j) z[i0][j] = true;
        K -= ansT.j2 - ansT.j1 + 1;
        node temp = g[i0][ansT.j1][ansT.j2][ansT.k][ansT.t];
        --i0;
        ansT = temp;
    }
    
    cout << "Oil : " << ans << endl;
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < M; ++j)
      if (z[i][j]) cout << i + 1 << " " << j + 1 << endl;
    
    
    return 0;
}
