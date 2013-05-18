#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1001;

int x[MAXN];

int main() {
    int n, k, a, b = 1;
    cin >> n >> k;
    x[0] = 1;
    a = k % n;
    while ((a * b + 1) % n) ++b;
    for (int i = 1; (i * b + 1) % n; ++i) x[(i * b + 1) % n] = 1;
    for (int i = 1; i < n; ++i) cout << x[i] + k / n << " ";
    cout << x[0] + k / n << endl;
    return 0;
}

