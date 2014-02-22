#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 6001;

int xx, yy;
int x[MAXN], y[MAXN];
double w[MAXN];


int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        double a;
        scanf("%lf", &a);
        w[i + 1] = a - 2;
        if (a > 2) x[xx++] = i + 1; else y[yy++] = i + 1;
    }
    double temp = 0;
    printf("yes\n");
    for (int i = 0; i < N; ++i) {
        if ((temp < 0 && xx > 0) || (yy == 0)) {
            printf("%d ", x[--xx]);
            temp += w[x[xx]];
            continue;
        }
        printf("%d ", y[--yy]);
        temp += w[y[yy]];
    }
    printf("\n");
    return 0;
}
