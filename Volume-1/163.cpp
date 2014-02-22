#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;



int main() {
    int N, P, ans = 0;
    cin >> N >> P;
    for (int i = 0; i < N; ++i) {
        int a, b = 1;
        cin >> a;
        for (int j = 0; j < P; ++j) b *= a;
        if (b > 0) ans += b;
    }
    cout << ans << endl;
    return 0;
}
