#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int n;
vector<int> x[MAXN];
int line[MAXN][2];
bool z[MAXN];
int ans[MAXN][MAXN];


int dfs(int a, bool &b, bool color) {
    z[a] = true;
    for (int i = 0; i < x[a].size(); ++i) {
        if (!z[x[a][i]]) {
            if (ans[a][x[a][i]] != 0) continue;
            ans[a][x[a][i]] = ans[x[a][i]][a] = color + 1;
            ++line[a][color];
            ++line[x[a][i]][color];
            bool bb = false;
            dfs(x[a][i], bb, !color);
            if (bb) {
                ans[a][x[a][i]] = ans[x[a][i]][a] = (!color) + 1;
                --line[a][color];
                --line[x[a][i]][color];
                ++line[a][!color];
                ++line[x[a][i]][!color];
                if (x[a].size() < 3) b = true;
            }
        } else {
            if (ans[a][x[a][i]] != 0) continue;
            ans[a][x[a][i]] = ans[x[a][i]][a] = color + 1;
            ++line[a][color];
            ++line[x[a][i]][color];
            if (line[x[a][i]][!color] == 0) {
                ans[a][x[a][i]] = ans[x[a][i]][a] = (!color) + 1;
                --line[a][color];
                --line[x[a][i]][color];
                ++line[a][!color];
                ++line[x[a][i]][!color];
                if (x[a].size() < 3) b = true;
            }
        }
    }
    return 0;
}


int dfs_root(int a) {
    bool color;
    z[a] = true;
    for (int i = 0; i < x[a].size(); ++i) {
        if (!z[x[a][i]]) {
            if (ans[a][x[a][i]] != 0) continue;
            bool flag = false;
            color = i;
            ans[a][x[a][i]] = ans[x[a][i]][a] = color + 1;
            ++line[a][color];
            ++line[x[a][i]][color];
            bool bb = false;
            dfs(x[a][i], bb, !color);
            if (bb) {
                ans[a][x[a][i]] = ans[x[a][i]][a] = (!color) + 1;
                --line[a][color];
                --line[x[a][i]][color];
                ++line[a][!color];
                ++line[x[a][i]][!color];
            }
        }
    }
    return 0;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        while (cin >> a) {
            if (a == 0) break;
            x[i].push_back(a);
        }
    }
    
    for (int i = 1; i <= n; ++i) 
     if (!z[i]) dfs_root(i);
    
    bool flag = false;
    for (int i = 1; i <= n; ++i) 
        flag |= x[i].size() > 1 && (line[i][0] == 0 || line[i][1] == 0);
  
    if (flag) {
        cout << "No solution" << endl;
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < x[i].size(); ++j) cout << ans[i][x[i][j]] << " ";
        cout << 0 << endl;
    }
    return 0;
}
