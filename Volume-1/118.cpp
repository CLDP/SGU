#include <iostream>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, tmp = 1, ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            a %= 9;
            tmp = (tmp * a) % 9;
            ans = (ans + tmp) % 9;
        }
        if (ans == 0) 
            cout << 9 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
