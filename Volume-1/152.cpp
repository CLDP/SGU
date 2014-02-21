#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 10001;

int x[MAXN], y[MAXN], z[MAXN];

int main() {
    int N, sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        sum += x[i];
    }
    int total = 100;
    for (int i = 0; i < N; ++i) {
        y[i] = x[i] * 100 / sum;
        z[i] = x[i] * 100 % sum;
        total -= y[i];
    }
    for (int i = 0; i < N; ++i) {
        if (z[i] > 0) {
            ++y[i];
            --total;
            if (total == 0) break;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << y[i];
        if (i != N - 1) cout << " "; else cout << endl;
    }
    return 0;
}
