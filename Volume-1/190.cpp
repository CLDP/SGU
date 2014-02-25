#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1610;

int n, m, e;
int l[MAXN];
bool x[MAXN][MAXN], z[MAXN], y[42][42];

bool find(int v) {
    for (int i = 1; i <= m; ++i) 
     if (!z[i] && x[v][i]) {
         z[i] = 1;
         int k = l[i];
         l[i] = v;
         if (!k || find(k)) return true;
         l[i] = k;
     }
    return false;
}

int make_edge(int N, int a, int b, int c, int d) {
    x[(a - 1) * N + b][(c - 1) * N + d] = true;
    return 0;
}

int main() {
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        y[a][b] = true;
    }
    if ((N * N - M) & 1) {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 1; i <= N; ++i) 
     for (int j = 1; j <= N; ++j) {
         if (y[i][j]) continue;
         if ((i + j) & 1) continue;
         if (i > 1 && !y[i - 1][j]) make_edge(N, i, j, i - 1, j);
         if (i < N && !y[i + 1][j]) make_edge(N, i, j, i + 1, j);
         if (j > 1 && !y[i][j - 1]) make_edge(N, i, j, i, j - 1);
         if (j < N && !y[i][j + 1]) make_edge(N, i, j, i, j + 1);
     }
    
    n = m = N * N;
    for (int i = 1; i <= n; ++i) {
        memset(z, 0, sizeof(z));
        find(i);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) ans += (l[i] > 0);
    
    if (ans != (n - M) / 2) {
        cout << "No" << endl;
        return 0;
    }
    
    vector<pair<int, int> > ans1, ans2;
    for (int i = 1; i <= m; ++i) {
        if (l[i] == 0) continue;
        int a = (i - 1) / N + 1, b = (i - 1) % N + 1;
        int c = (l[i] - 1) / N + 1, d = (l[i] - 1) % N + 1;
        if (a == c)
            ans2.push_back(make_pair(a, min(b, d))); 
        else 
            ans1.push_back(make_pair(min(a, c), b));
    }
    cout << "Yes" << endl;
    cout << ans1.size() << endl;
    for (int i = 0; i < ans1.size(); ++i) cout << ans1[i].first << " " << ans1[i].second << endl;
    cout << ans2.size() << endl;
    for (int i = 0; i < ans2.size(); ++i) cout << ans2[i].first << " " << ans2[i].second << endl;
    
    return 0;
}
