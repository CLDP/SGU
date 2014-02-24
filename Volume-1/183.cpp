#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int INF = 1000000000;

int f[MAXN][102];

int main() {
    int N, K, a, ans = INF;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        for (int j = i - 1; j >= max(0, i - K + 1); --j) {
            f[i][i - j] = INF;
            for (int k = j - 1; k >= max(0, i - K); --k) f[i][i - j] = min(f[i][i - j], f[j][j - k]);
            if (j == 0) f[i][i - j] = 0;
            f[i][i - j] += a;
            if (j >= N - K + 1) ans = min(ans, f[i][i - j]);
        }
    }
    cout << ans << endl;
    
    return 0;
}
