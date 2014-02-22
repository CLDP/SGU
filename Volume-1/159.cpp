#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 2010;

int KM, ans, N;
int f[MAXN][MAXN], x[MAXN];


int dfs(int pos, int sum) {
    if (pos == N) {
        if (x[pos - 1] > 0 || N == 1) {
            for (int i = 0; i < N; ++i) f[ans][i] = x[i];
            ++ans;
        }
        return 0;
    }
    for (int i = 0; i < KM; ++i) {
        x[pos] = i;
        int temp = 0;
        for (int j = 0; j <= pos; ++j) temp += x[j] * x[pos - j];
        if ((sum + temp) % KM == i) {
            dfs(pos + 1, (sum + temp) / KM);
        }
    }
    return 0;
}


int main() {
    cin >> KM >> N;
    dfs(0, 0);
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            if (f[i][j] >= 10)
                printf("%c", f[i][j] - 10 + 'A');
            else
                printf("%d", f[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
