#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int main() {
    double L;
    int N;
    cin >> L >> N;
    long long LL = L * 10000 + 0.5;
    long long a, b, run = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        run += a * b * 10000;
        run %= LL;
    }
    if (LL - run < run) run = LL - run;
    printf("%.4lf\n", run / 10000.0);
    
    return 0;
}
