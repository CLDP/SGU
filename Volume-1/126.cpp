#include <iostream>
using namespace std;


int main() {
    long long a, b;
    cin >> a >> b;
    
    if (a == 0 || b == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 1; i < 40; ++i) {
        if (a == b) {
            cout << i << endl;
            return 0;
        }
        if (a < b) {
            a += a;
            b -= a / 2;
        } else {
            b += b;
            a -= b / 2;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}
