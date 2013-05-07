#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 33000;

bool noprime[MAXN];

bool prime(int a) {
    int b = sqrt(a + 1);
    for (int i = 2; i <= b; ++i)
     if (a / i * i == a) return false;
    return true;
}

int main() {
    int n, a, b;
    n = 2;
    noprime[0] = noprime[1] = true;
    while (n < MAXN) {
        if (!noprime[n]) {
            a = n;
            while (n + a < MAXN) {
                a += n;
                noprime[a] = true;
            }
        }
        ++n;
    }
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        b = sqrt(a + 1);
        bool flag = false;
        for (int j = 2; j <= b; ++j)
         if (a / j * j == a && !noprime[j]) {
             if ((a / j < MAXN && !noprime[a / j]) || (a / j >= MAXN && prime(a / j))) {
                 flag = true;
                 break;
             }
         }
        if (flag)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}
