#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const double PI = 3.14159265358979323846;

struct point {
    double x, y;
};

point point1, point2, points[151];

double zero(double a) {
    return fabs(a) < 1e-8 ? 0 : a;
}

int main() {
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    cin >> point1.x >> point1.y >> point2.x >> point2.y;
    if (n2 < n1) {
        swap(n1, n2);
        swap(point1, point2);
    }
    
    point mid = {(point1.x + point2.x) / 2, (point1.y + point2.y) / 2};
    double theta = PI * (n2 - n1) / n;
    if (n2 - n1 < n / 2) 
        theta += PI * 1.5;
    else 
        theta -= PI * 0.5;
        
    double tangent = tan(theta);
    point center = {mid.x - (mid.y - point1.y) * tangent, (mid.x - point1.x) * tangent + mid.y};
    point1.x -= center.x;
    point1.y -= center.y;
    points[n1].x = point1.x;
    points[n1].y = point1.y;
    
    double sine = sin(PI * 2 / n), cosine = cos(PI * 2 / n);
    for (int i = 1, j = n1 + 1; i < n; ++i, ++j) {
        if (j > n) j -= n;
        points[j].x = point1.x * cosine + point1.y * sine;
        points[j].y = -point1.x * sine + point1.y * cosine;
        point1 = points[j];
    }
    
    for (int i = 1; i <= n; ++i) printf("%.6lf %.6lf\n", zero(points[i].x + center.x), 
                                                         zero(points[i].y + center.y));
    return 0;
}
