#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;



int main() {
    double c, b, m, x, y;
    cin >> c >> b >> m;
    if (2 * m < fabs(c - b) || 2 * m > b + c) {
        cout << "Mission impossible" << endl;
    } else {
        x = (4 * m * m - c * c - b * b) / c / 2;
        y = b * b - x * x;
        if (y >= 0) y = sqrt(y); else y = 0;
        printf("%.5lf %.5lf\n%.5lf %.5lf\n%.5lf %.5lf\n", 0.0, 0.0, c, 0.0, x, y);
    }
    return 0;
}
