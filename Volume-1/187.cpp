#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

int l[2][MAXN], r[2][MAXN];


int print(int S) {
    for (int i = 1; i <= S; ++i) {
        int c = r[0][i] > l[0][i] ? 1 : -1;
        for (int j = l[0][i]; j != r[0][i] + c; j += c) printf("%d ", j);
    }
    printf("\n");
}


int main() {
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    int S = 1;
    l[0][1] = 1, r[0][1] = N;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        int p = 0, temp = 0, SS = 0, left, right;
        while (temp < a) {
            ++p;
            temp += abs(r[0][p] - l[0][p]) + 1;
            ++SS;
            l[1][SS] = l[0][p];
            r[1][SS] = r[0][p];
        }
        int prev = temp - abs(l[0][p] - r[0][p]);
        left = p;
        if (prev != a) {
            r[1][SS] = l[1][SS] + (a - prev - 1) * (r[0][p] > l[0][p] ? 1 : -1);
            ++SS;
            l[1][SS] = r[1][SS - 1] + (r[0][p] > l[0][p] ? 1 : -1);
            r[1][SS] = r[0][p];
            ++left;
        }
        
        right = left;
        while (temp < b) {
            ++p;
            temp += abs(r[0][p] - l[0][p]) + 1;
            ++SS;
            l[1][SS] = l[0][p];
            r[1][SS] = r[0][p];
            ++right;
        }
        if (temp != b) {
            r[1][SS] -= (temp - b) * (r[0][p] > l[0][p] ? 1 : -1);
            ++SS;
            l[1][SS] = r[1][SS - 1] + (r[0][p] > l[0][p] ? 1 : -1);
            r[1][SS] = r[0][p];
        }
        
        for (int k = p + 1; k <= S; ++k) {
            ++SS;
            l[1][SS] = l[0][k];
            r[1][SS] = r[0][k];
        }
        S = SS;
        SS = 0;
        for (int j = 1; j < left; ++j) {
            ++SS;
            l[0][SS] = l[1][j];
            r[0][SS] = r[1][j];
        }
        for (int j = right; j >= left; --j) {
            ++SS;
            l[0][SS] = r[1][j];
            r[0][SS] = l[1][j];
        }
        for (int j = right + 1; j <= S; ++j) {
            ++SS;
            l[0][SS] = l[1][j];
            r[0][SS] = r[1][j];
        }
    }
    print(S);
    
    return 0;
}
