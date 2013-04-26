#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long extended_gcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return d;
    }
    extended_gcd(b, a % b, d, y, x);
    y -= x * (a / b);
    return d;
}


int main() {
    long long a, b, c, d, x1, x2, y1, y2, x, y, aa, bb;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    aa = a, bb = b, c = -c;
    
    if (x1 > x2 || y1 > y2) {
        cout << 0 << endl;
        return 0;
    }
    
    if (a == 0 && b == 0) {
        if (c == 0) 
            cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    
    if (a == 0) {
        if (c % b == 0 && y1 <= c / b && c / b <= y2)
            cout << x2 - x1 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    
    if (b == 0) {
        if (c % a == 0 && x1 <= c / a && c / a <= x2) 
            cout << y2 - y1 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    
    long long sx = a > 0 ? 1 : -1, sy = b > 0 ? 1 : -1;
    if (c < 0) {
        sx = -sx;
        sy = -sy;
    }
    
    a = abs(a), b = abs(b), c = abs(c);
    
    extended_gcd(a, b, d, x, y);
    
    if (c % d != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    x *= c / d;
    y *= c / d;
    x *= sx, y *= sy;
    
    a = aa / d, b = bb / d;
    
    if (a < 0) swap(y1, y2);
    if (b < 0) swap(x1, x2);
    
    long long ans1 = max(ceil((double)(x1 - x) / b), ceil((double)(y - y2) / a));
    long long ans2 = min(floor((double)(x2 - x) / b), floor((double)(y - y1) / a));
    
    if (ans1 <= ans2) 
        cout << ans2 - ans1 + 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
