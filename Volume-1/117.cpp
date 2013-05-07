#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int x[MAXN], y[MAXN];

int main() {
    int n, m, k, a, ans = 0, maxk;
    cin >> n >> m >> k;
    for (int i = 2; i < 10000; ++i) {
        if (k == 1) break;
        maxk = i;
        while (k % i == 0) {
            k /= i;
            ++x[i];
        }
    }
    
    while (n > 0) {
        --n;
        cin >> a;
        memset(y, 0, sizeof(y));
        for (int i = 2; i < 10000; ++i) {
            if (a == 1) break;
            while (a % i == 0) {
                a /= i;
                y[i] += m;
            }
        }
        bool flag = true;
        for (int i = 2; i <= maxk; ++i) {
            flag &= (x[i] <= y[i]);
            if (!flag) break;
        }
        if (flag) ++ans;
    }
    
    cout << ans << endl;

    return 0;
}
