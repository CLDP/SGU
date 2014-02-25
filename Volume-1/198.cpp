#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 310;
const double EPS = 1e-6;

struct circle {
    double a, b, r;
};

struct seg {
    double a, b;
};

circle y[MAXN];
vector<pair<int, double> > x[MAXN];
double d[MAXN];
bool z[MAXN];
int f[MAXN];

double dot(const seg &A, const seg &B) {
    return A.a * B.a + A.b * B.b;
}

double cross(const seg &A, const seg &B) {
    return A.a * B.b - A.b * B.a;
}

int sign(const double &A) {
    if (fabs(A) < EPS) return 0;
    return A > 0 ? 1 : -1;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> y[i].a >> y[i].b >> y[i].r;
    circle P;
    cin >> P.a >> P.b >> P.r;
    
    for (int i = 0; i < N; ++i)
     for (int j = 0; j < N; ++j) {
         if (i == j) continue;
         if (sqrt((y[i].a - y[j].a) * (y[i].a - y[j].a) 
                + (y[i].b - y[j].b) * (y[i].b - y[j].b)) 
                - y[i].r - y[j].r >= P.r * 2 - EPS) continue;
         seg A, B;
         A.a = y[i].a - P.a, A.b = y[i].b - P.b;
         B.a = y[j].a - P.a, B.b = y[j].b - P.b;
         double theta = acos(fabs(dot(A, B)) / sqrt(fabs(dot(A, A) * dot(B, B))));
         if (fabs(theta) < EPS) continue;
         x[j].push_back(make_pair(i, theta * sign(cross(B, A))));
     }
    
    queue<int> que;
    for (int i = 1; i <= N; ++i) {
        z[i] = true;
        que.push(i);
    }
    
    while (!que.empty()) {
        int a = que.front();
        que.pop();
        for (int i = 0; i < x[a].size(); ++i) {
            if (d[x[a][i].first] > d[a] + x[a][i].second + EPS) {
                d[x[a][i].first] = d[a] + x[a][i].second;
                if (!z[x[a][i].first]) {
                    z[x[a][i].first] = true;
                    que.push(x[a][i].first);
                    ++f[x[a][i].first];
                    if (f[x[a][i].first] > N) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
        
        z[a] = false;
    }
    
    cout << "YES" << endl;
    
    return 0;
}
