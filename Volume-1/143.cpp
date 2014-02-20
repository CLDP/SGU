#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 16010;

vector<int> x[MAXN];
int y[MAXN], s[MAXN];
int global_ans;


int dfs(int a, int f) {
    s[a] = 1;
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == f) continue;
        s[a] += dfs(x[a][i], a);
    }
    return s[a];
}

int dp(int a, int f) {
    int ans = y[a];
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == f) continue;
        ans += dp(x[a][i], a);
    }
    if (ans < 0) ans = 0;
    return ans;
}

int calculate(int root) {
    dfs(root, -1);
    int curr = root, prev = -1;
    while (true) {
        bool flag = false;
        int next;
        for (int i = 0; i < x[curr].size(); ++i) {
            if (x[curr][i] == prev) continue;
            if (s[x[curr][i]] >= s[root] / 2) {
                flag = true;
                next = x[curr][i];
                break;
            }
        }
        if (!flag) break;
        prev = curr;
        curr = next;
    }
    
    int ans = y[curr];
    for (int i = 0; i < x[curr].size(); ++i) ans += dp(x[curr][i], curr);
    global_ans = max(global_ans, ans);
    
    for (int i = 0; i < x[curr].size(); ++i) {
        int a = x[curr][i];
        for (int j = 0; j < x[a].size(); ++j) {
            if (x[a][j] == curr) {
                x[a].erase(x[a].begin() + j);
                break;
            }
        }
        calculate(a);
    }
    return 0;
}


int main() {
    int N, a, b;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &y[i]);
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d%d", &a, &b);
        x[a].push_back(b);
        x[b].push_back(a);
    }
    calculate(1);
    if (global_ans == 0) {
        global_ans = -1000;
        for (int i = 1; i <= N; ++i) global_ans = max(global_ans, y[i]);
    }
    
    cout << global_ans << endl;
    
    return 0;
}
