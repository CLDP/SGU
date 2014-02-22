#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 310;

int p[MAXN], d[MAXN], x[MAXN];


int main() {
    int l, m;
    cin >> l >> m;
    l <<= 1;
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        p[i] <<= 1;
    }
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> d[i];
        d[i] <<= 1;
        x[i - 1] = (d[i] + d[i - 1]) >> 1;
    }
    int ans = -1, pos = 0;
    for (int s = 0; s + d[n - 1] <= l; ++s) {
        int sum = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n - 1 && x[j] + s < p[i]) ++j;
            sum += abs(d[j] + s - p[i]);
        }
        if (sum > ans) {
            ans = sum;
            pos = s;
        }
    }
    cout << pos / 2;
    if (pos & 1) cout << ".5";
    cout << " ";
    cout << ans / 2;
    if (ans & 1) cout << ".5";
    cout << endl;

    return 0;
}
