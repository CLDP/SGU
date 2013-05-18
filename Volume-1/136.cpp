#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10010;

double x[MAXN], y[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        x[0] += i & 1 ? x[i] : -x[i];
        y[0] += i & 1 ? y[i] : -y[i];
    }
    if (n % 2 == 0) {
        if (x[0] == y[0] && y[0] == 0)
            x[0] = y[0] = 0.5;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    printf("YES\n%.3lf %.3lf\n", x[0], y[0]);
    for (int i = 1; i < n; ++i) {
        x[i] = x[i] * 2 - x[i - 1];
        y[i] = y[i] * 2 - y[i - 1];
        printf("%.3lf %.3lf\n", x[i], y[i]);
    }
    
    return 0;
}
