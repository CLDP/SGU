#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

long long x[30], y[30];


int main() {
    int N;
    cin >> N;
    x[1] = 1;
    y[1] = 5;
    int i;
    for (i = 1; x[i] < N; ++i) {
        x[i + 1] = 5 * x[i] + 1;
        y[i + 1] = 5 * y[i];
    }
    long long ans = 0;
    int M = N;
    while (N > 0) {
        if (N >= x[i]) {
            ans += y[i];
            N -= x[i];
        } else {
            --i;
        }
    }
    long long temp = ans;
    i = 1;
    while (y[i] < temp) ++i;
    while (temp > 0) {
        if (temp >= y[i]) {
            N += x[i];
            temp -= y[i];
        } else {
            --i;
        }
    }
    if (ans == 0) ans = 1;
    if (N == M)
        cout << ans << endl;
    else 
        cout << "No solution" << endl;
        
    return 0;
}
