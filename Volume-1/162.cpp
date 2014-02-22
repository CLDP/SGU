#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;


double volume(double a, double b, double c, double a1, double b1, double c1) {
    double m = b * b + c * c - a1 * a1;
    double n = a * a + c * c - b1 * b1;
    double p = a * a + b * b - c1 * c1;
    return sqrt(a * a * b * b * c * c - (a * a * m * m + b * b * n *n + c * c * p * p ) / 4 
              + m * n * p / 4 ) / 6;
}
 
int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    printf("%.4f\n",volume(a,b,c,f,e,d));
    
    return 0;
}
