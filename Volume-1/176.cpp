#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int INF = 1000000000;

int N, M, diff;
int in[MAXN], f[MAXN][MAXN];
vector<pair<int, int> > y;
vector<pair<int, int> > x[MAXN], xx[MAXN];


int max_flow(int s, int t, int n) {
    vector<int> ff(n + 1, 0);
    vector<int> fa(n + 1, 0);
    vector<int> h(n + 1, 0);
    vector<int> hh(n + 1, 0);
    vector<int> fi(n + 1, 0);
    
    int i = 0, now, ans = 0;
    hh[0] = n;
    
    i = s;
    now = INF;
    
    while (h[s] < n) {
        ff[i] = now;
        bool flag = false;
        vector<pair<int, int> >::iterator p = x[i].begin();
        while (p != x[i].end()) {
            if (p->second > 0 && h[p->first] + 1 == h[i]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fi[p->first] = p - x[i].begin();
                i = p->first;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = x[i].begin() + fi[tmp];
                        p->second -=now;
                        x[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        
        int min = n-1;
        p = x[i].begin();
        while (p != x[i].end()) {
            if (p->second > 0 && h[p->first] < min) min = h[p->first];
            ++p;
        }
        
        --hh[h[i]];
        if (hh[h[i]] == 0) break;
        h[i] = min + 1;
        ++hh[h[i]];
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}

bool check(int A) {
    int s = N + 1, t = s + 1;
    for (int i = 1; i <= t; ++i) x[i] = xx[i];
    x[N].push_back(make_pair(1, A));
    int ans = max_flow(s, t, t);
    return ans == diff;
}

int output() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < x[i].size(); ++j) {
            if (x[i][j].first > N) continue;
            f[i][x[i][j].first] -= x[i][j].second;
        }
    }
    for (int i = 0; i < M; ++i) {
        cout << f[y[i].first][y[i].second];
        if (i != M - 1) cout << " ";
    }
    cout << endl;
}


int main() {
    int a, b, c, d;
    scanf("%d%d", &N, &M);
    int s = N + 1, t = s + 1;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        y.push_back(make_pair(a, b));
        if (d == 0) {
            xx[a].push_back(make_pair(b, c));
        } else {
            in[a] -= c;
            in[b] += c;
        }
        f[a][b] += c;
    }
    
    for (int i = 1; i <= N; ++i) {
        if (in[i] == 0) continue;
        if (in[i] > 0) xx[s].push_back(make_pair(i, in[i]));
        if (in[i] < 0) xx[i].push_back(make_pair(t, -in[i]));
        if (in[i] > 0) diff += in[i];
    }
    int L = 0, R = 10000000;
    if (check(L)) {
        cout << L << endl;
        output();
        return 0;
    }
    if (!check(R)) {
        cout << "Impossible" << endl;
        return 0;
    }
    while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid; else L = mid;
    }
    // Renew x matrix
    check(R);
    cout << R << endl;
    output();

    return 0;
}
