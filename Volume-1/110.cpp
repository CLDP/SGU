#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const double INF = 1e10;

struct point {
    double x, y, z, r;
};

int n;
vector<point> ball;

int sign(double x) {
    if (fabs(x) < 1e-8) return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}


double dot(point a, point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


double time(point now, point ball, point dir) {
    double a = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
    double b = 2 * ((now.x - ball.x) * dir.x + (now.y - ball.y) * dir.y + (now.z - ball.z) * dir.z);
    double c = (now.x - ball.x) * (now.x - ball.x) + (now.y - ball.y) * (now.y - ball.y) 
             + (now.z - ball.z) * (now.z - ball.z) - ball.r * ball.r;
    double delta = b * b - 4 * a * c;
    if (sign(delta) == -1) return INF;
    delta = sqrt(delta);
    double x1 = (- b + delta) / (2 * a);
    double x2 = (- b - delta) / (2 * a);
    if (sign(x2) > 0) return x2;
    if (sign(x1) > 0) return x1;
    return INF;
}


int main() {
    cin >> n;
    point now, dir;
    for (int i = 0; i < n; ++i) {
        cin >> now.x >> now.y >> now.z >> now.r;
        ball.push_back(now);
    }
    cin >> now.x >> now.y >> now.z >> dir.x >> dir.y >> dir.z;
    // Note: input direction is not absolute direction!
    dir.x -= now.x;
    dir.y -= now.y;
    dir.z -= now.z;
    
    for (int i = 0; i < 11; ++i) {
        vector<pair<double, int> > balls;
        for (int j = 0; j < n; ++j) balls.push_back(make_pair(time(now, ball[j], dir), j));
        sort(balls.begin(), balls.end());
        if (!sign(balls[0].first - INF)) break;
        if (i != 0) cout << " ";
        if (i == 10) {
            cout << "etc.";
            break;
        }
        cout << balls[0].second + 1;
        now.x += balls[0].first * dir.x;
        now.y += balls[0].first * dir.y;
        now.z += balls[0].first * dir.z;
        point normal;
        normal.x = now.x - ball[balls[0].second].x;
        normal.y = now.y - ball[balls[0].second].y;
        normal.z = now.z - ball[balls[0].second].z;
        if (sign(dot(normal, dir)) == 0) continue;
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
        double scal = 2 * dot(normal, dir) / (normal.x * normal.x + normal.y * normal.y 
                                            + normal.z * normal.z);
        dir.x = normal.x * scal - dir.x;
        dir.y = normal.y * scal - dir.y;
        dir.z = normal.z * scal - dir.z;
    }
    cout << endl;
    
    return 0;
}
