#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 102;

int N, M, K, s, t, count;
int x[MAXN][MAXN];
bool z[MAXN];
vector<int> ansT;


int dfs(int a, int d, int mid) {
    if (a == t) {
        ++count;
        return 0;
    }
    z[a] = true;
    for (int i = 1; i <= N; ++i) {
        if (!z[i] && x[a][i] && d + x[a][i] <= mid) {
            dfs(i, d + x[a][i], mid);
            if (count >= K) break;
        }
    }
    z[a] = false;
    return 0;
}

bool dfs_find(int a, int d, int R) {
    if (a == t) {
        if (d == R) {
            ansT.push_back(a);
            return true;
        } else {
            return false;
        }
    }
    z[a] = true;
    for (int i = 1; i <= N; ++i) {
        if (!z[i] && x[a][i] && d + x[a][i] <= R && dfs_find(i, d + x[a][i], R)) {
            ansT.push_back(a);
            return true;
        }
    }
    z[a] = false;
    return false;
}



int main() {
    cin >> N >> M >> K;
    int L = 0, R = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x[a][b] = x[b][a] = c;
        R += c;
    }
    cin >> s >> t;
    while (L + 1 < R) {
        int mid = (L + R) >> 1;
        count = 0;
        dfs(s, 0, mid);
        if (count < K) L = mid; else R = mid;
    }
    dfs_find(s, 0, R);
    cout << R << " " << ansT.size() << "\n";
    for (int i = ansT.size() - 1; i >= 0; --i) {
        cout << ansT[i];
        if (i == 0) cout << "\n"; else cout << " ";
    }
    
    return 0;
}
