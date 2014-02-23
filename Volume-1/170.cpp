#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 5010;

char x[MAXN], y[MAXN];

int main() {
    scanf("%s%s", x, y);
    int N = strlen(x);
    if (strlen(y) != N) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> xx, yy;
    for (int i = 0; i < N; ++i) {
        if (x[i] == '+') xx.push_back(i);
        if (y[i] == '+') yy.push_back(i);
    }
    if (xx.size() != yy.size()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    N = xx.size();
    for (int i = 0; i < N; ++i) ans += abs(xx[i] - yy[i]);
    cout << ans << endl;

    return 0;
}
