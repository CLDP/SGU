#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 2010;
const int TRY = 2000;

int N, M, x[10];
bool f[MAXN], z[MAXN];

bool dp(int a) {
    if (z[a]) return f[a];
    z[a] = true;
    f[a] = false;
    for (int i = 0; i <= M; ++i) {
        if (a < x[i]) continue;
        f[a] |= !dp(a - x[i]);
    }
    return f[a];
}

bool check(int a) {
    for (int i = 0; i <= 9; ++i) {
        if (f[TRY - i] != f[a - i]) return false;
    }
    return true;
}

int main() {
    int times;
    cin >> times;
    while (times--) {
        cin >> N >> M;
        x[0] = 1;
        for (int i = 1; i <= M; ++i) cin >> x[i];
        memset(z, 0, sizeof(z));
        z[0] = f[0] = true;
        if (N < TRY) {
            dp(N);
        } else {
            dp(TRY);
            for (int i = TRY - 1; i >= 0; --i) {
                if (check(i)) {
                    N = N % (TRY - i);
                    break;
                }
            }
        }
        if (f[N]) cout << "FIRST"; else cout << "SECOND";
        cout << " PLAYER MUST WIN" << endl;
    }
    return 0;
}
