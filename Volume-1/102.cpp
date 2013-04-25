#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    int t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int n, ans = 0;
    cin >> n;
    
    // The return value for 1 is 1!!!
    for (int i = 1; i <= n; ++i)
     if (gcd(n, i) == 1) ++ans;
    
    cout << ans << endl;
    
    return 0;
}
