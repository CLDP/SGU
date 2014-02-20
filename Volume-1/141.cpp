#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int gcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
        return b;
    }
    gcd(b, a % b, d, y, x);
    y -= x * (a / b);
    return d;
}


int main() {
    int x1, x2, p, k;
    cin >> x1 >> x2 >> p >> k;
    
    int A, B, D;
    int GCD = gcd(x1, x2, D, A, B);
    if (abs(p) % GCD != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    A *= p / GCD;
    B *= p / GCD;
    int d1 = x2 / GCD, d2 = x1 / GCD;
    
    while (abs(A - d1) + abs(B + d2) < abs(A) + abs(B)) A -= d1, B += d2;
    while (abs(A + d1) + abs(B - d2) < abs(A) + abs(B)) A += d1, B -= d2;
    if (abs(A) + abs(B) > k) {
        cout << "NO" << endl;
        return 0;
    }
    
    if ((k - abs(A) - abs(B)) & 1) {
        if (((d1 + d2) & 1) == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (abs(A - d1) + abs(B + d2) < abs(A + d1) + abs(B - d2))
            A -= d1, B += d2;
        else
            A += d1, B -= d2;
        if (abs(A) + abs(B) > k) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    int t = (k - abs(A) - abs(B)) / 2;
    int p1, n1, p2, n2;
    if (A < 0) p1 = t, n1 = t - A; else p1 = t + A, n1 = t;
    if (B < 0) p2 = 0, n2 = -B; else p2 = B, n2 = 0;
    cout << "YES" << endl << p1 << " " << n1 << " " << p2 << " " << n2 << endl;
    
    return 0;
}
