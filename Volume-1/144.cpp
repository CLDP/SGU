#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int main() {
    double X, Y, Z;
    cin >> X >> Y >> Z;
    double L = (Y - X) * 60;
    double ans = 1.0 - ((L - Z) * (L - Z)) / (L * L);
    printf("%.7lf\n", ans);
    
    return 0;
}
