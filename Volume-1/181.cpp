#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

long long x[MAXN];

int main() {
    long long A, B, C, M, K;
    cin >> x[0] >> A >> B >> C >> M >> K;
    for (int i = 1; i < MAXN; ++i) x[i] = (A * x[i - 1] * x[i - 1] + B * x[i - 1] + C) % M;
    if (K < MAXN) {
        cout << x[K] << endl;
        return 0;
    }
    
    int t = MAXN - 1, s = t - 1;
    while (x[s] != x[t]) --s;
    K = s + (K - s) % (t - s);
    cout << x[K] << endl;
    
    return 0;
}
