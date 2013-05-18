#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAXN = 101;

int p;
int a[MAXN], x[MAXN], y[MAXN], ans[MAXN];

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int tmp = gcd(b % a, a, x, y), t = x;
    x = y - b / a * x;
    while (x < 0) x += p;
    y = t;
    return tmp;
}


int main() {
    int n, b;
    cin >> n >> p >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= p;
    }
    
    int v = a[1];
    for (int i = 2; i <= n; ++i) v = gcd(v, a[i], x[i], y[i]);
    
    int tmp, xx;
    v = gcd(v, p, xx, tmp);

    if (b % v) {
        cout << "NO" << endl;
        return 0;
    }
    
    xx = xx * b / v % p;
    for (int i = n; i > 1; --i) {
        ans[i] = xx * y[i] % p;
        xx = xx * x[i] % p;
    }
    ans[1] = xx;
    cout << "YES" << endl;
    for(int i = 1; i < n; ++i) cout << ans[i] << " ";
    cout << ans[n] << endl;
    
    return 0;
}
