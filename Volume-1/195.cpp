#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500010;

int f[MAXN], d[MAXN];
bool z[MAXN];

int main() {
    int N, a;
    scanf("%d", &N);
    for (int i = 2; i <= N; ++i) {
        scanf("%d", &a);
        f[i] = a;
        ++d[i];
        ++d[a];
    }
    
    queue<int> que;
    for (int i = 1; i <= N; ++i) 
     if (d[i] == 1) que.push(i);
    
    z[0] = true;
    vector<int> ans;
    while (!que.empty()) {
        a = que.front();
        que.pop();
        if (!z[a] && !z[f[a]]) {
            ans.push_back(a);
            z[a] = z[f[a]] = true;
        }
        --d[f[a]];
        if (d[f[a]] == 1) que.push(f[a]);
    }
    
    sort(ans.begin(), ans.end());
    cout << 1000 * ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
