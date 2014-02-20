#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const double INF = 1e8;

int x1, y1, x2, y2, N;


int inter(int pos, double x, double y) {
    int q = int(x + INF) - INF, h = int(y + INF) - INF;
    if (x > y) {
        q -= (q >= x);
        if (N <= q - h + 1) {
            cout << pos << " " << q - N + 1 << endl;
            exit(0);
        } else
            return q - h + 1;
    } else {
        h -= (h >= y);
        if (N <= h - q + 1) {
            cout << pos << " " << q + N - 1 << endl;
            exit(0);
        } else 
            return h - q + 1;
    }
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> N;
    if (y1 == y2 || x1 == x2) {
        cout << "no solution" << endl;
        return 0;
    }
    
    double l = x1 > x2 ? -1 : 1;
    for (int i = x1 + l; i != x2 + l && N > 0; i += l) {
        double K1 = i - l - x1;
        K1 *= (y2 - y1) * 1.0;
        K1 /= (x2 - x1) * 1.0;
        double K2 = i - x1;
        K2 *= (y2 - y1) * 1.0;
        K2 /= (x2 - x1) * 1.0;
        N -= inter(i - (x1 < x2), y1 + K1, y1 + K2);
    }
    cout << "no solution" << endl;
    return 0;
}
