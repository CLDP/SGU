#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 10010;

int ANS[MAXN], D[MAXN], F[MAXN];
vector<pair<int, int> > x[MAXN];

int dfs(int a, int f) {
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i].first == f) continue;
        dfs(x[a][i].first, a);
        D[a] = max(D[a], D[x[a][i].first] + x[a][i].second);
    }
    return 0;
}

int dfs_cal(int a, int f) {
    ANS[a] = max(D[a], F[a]);
    multiset<int> C;
    C.insert(F[a]);
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i].first == f) continue;
        C.insert(D[x[a][i].first] + x[a][i].second);
    }
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i].first == f) continue;
        C.erase(C.find(D[x[a][i].first] + x[a][i].second));
        F[x[a][i].first] = x[a][i].second + *(--C.end());
        C.insert(D[x[a][i].first] + x[a][i].second);
        dfs_cal(x[a][i].first, a);
    }
    return 0;
}

int main() {
    int N, a, b;
    scanf("%d", &N);
    for (int i = 2; i <= N; ++i) {
        scanf("%d%d", &a, &b);
        x[i].push_back(make_pair(a, b));
        x[a].push_back(make_pair(i, b));
    }
    
    dfs(1, -1);
    dfs_cal(1, -1);
    
    for (int i = 1; i <= N; ++i) printf("%d\n", ANS[i]);
    
    return 0;
}
