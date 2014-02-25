#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 30010;

char x[MAXN * 2], y[MAXN];

int main() {
    scanf("%s%s", x + MAXN, y);
    int N = strlen(x + MAXN), M = strlen(y);
    for (int i = 0, j = MAXN; i <= M; ++i) {
        if (i == M) {
            if (j == MAXN + N) 
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
            break;
        }
        if (x[j] == y[i]) {
            x[j - 1] = !(x[j] - 'A') + 'A';
            --j;
        } else {
            ++j;
        }
    }
    return 0;
}
