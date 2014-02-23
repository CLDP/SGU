#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int N, q;
    cin >> N >> q;
    int ans = 0;
    while (N > 1) {
        int K = N / 2;
        if (q > K) {
            q = N + 1 - q;
            N = N - K;
        } else {
            ans += N - K;
            q = K + 1 - q;
            N = K;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
