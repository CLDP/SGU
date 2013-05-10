#include <iostream>
using namespace std;

int x[10];

int main() {
    int k, n, a;
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++x[a / 1000];
    }
    
    int ans = 2;
    for (int i = 1; i <= 9; ++i) ans += (x[i] + k - 1) / k;
    
    cout << ans << endl;
    
    return 0;
}
