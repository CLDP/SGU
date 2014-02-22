#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 10010;
const int MAXM = 1010;

int x[MAXN];
bool y[MAXM], z[MAXM];
int f[MAXM], p[MAXM];


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%d", &x[i]);
    
    y[1] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < M; ++j) z[j] = y[j];
        for (int j = 1; j < M; ++j) {
            if (!y[j]) continue;
            int b = j * x[i] % M;
            if (z[b]) continue;
            z[b] = true;
            f[b] = j;
            p[b] = i + 1;
        }
        for (int j = 1; j < M; ++j) y[j] = z[j];
    }
    
    for (int i = M - 1; i >= 1; --i) {
        if (!y[i]) continue;
        cout << i << endl;
        vector<int> ans;
        int j = i;
        while (j != 1) {
            ans.push_back(p[j]);
            j = f[j];
        }
        if (ans.size() > 0) {
            for (int i = ans.size() - 1; i > 0; --i) printf("%d ", ans[i]);
            printf("%d\n", ans[0]);
        }
        break;
    }
    
    return 0;
}
