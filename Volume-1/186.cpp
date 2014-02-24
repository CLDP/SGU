#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int x[110];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x, x + N);
    int l = 0, r = N - 1, ans = 0;
    while (l < r) {
        ++ans;
        --x[l];
        --r;
        if (x[l] == 0) ++l;
    }
    cout << ans << endl;
    return 0;
}
