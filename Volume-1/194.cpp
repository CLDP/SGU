#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int INF = 1000000000;

struct node {
    int v, c;
    int pair;
};

int in[MAXN];
vector<node> x[MAXN];
vector<pair<int, int> > z;
int y[MAXN][MAXN];

int new_edge(int a, int b, int c) {
    node P, Q;
    P.v = b, P.c = c, P.pair = x[b].size();
    Q.v = a, Q.c = 0, Q.pair = x[a].size();
    x[a].push_back(P);
    x[b].push_back(Q);
    return 0;
}


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
        vector<node>::iterator p = x[i].begin();
        while (p != x[i].end()) {
            if (p->c > 0 && h[p->v] + 1 == h[i]) {
                flag = true;
                if (p->c < now) now = p->c;
                fa[p->v] = i;
                fi[p->v] = p - x[i].begin();
                i = p->v;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = x[i].begin() + fi[tmp];
                        p->c -=now;
                        (x[tmp].begin() + p->pair)->c += now;
                    }
                    now = INF;
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        
        int min = n - 1;
        p = x[i].begin();
        while (p != x[i].end()) {
            if (p->c > 0 && h[p->v] < min) min = h[p->v];
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


int main() {
    int N, M;
    cin >> N >> M;
    int s = N + 1, t = s + 1;
    for (int i = 0; i < M; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        new_edge(a, b, d - c);
        in[b] += c;
        in[a] -= c;
        z.push_back(make_pair(a, b));
        y[a][b] += d;
    }
    
    int total = 0;
    for (int i = 1; i <= N; ++i) {
        if (in[i] == 0) continue;
        if (in[i] > 0) new_edge(s, i, in[i]); else new_edge(i, t, -in[i]);
        if (in[i] > 0) total += in[i];
    }
    
    if (max_flow(s, t, t) != total) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    for (int i = 1; i <= N; ++i)
     for (int j = 0; j < x[i].size(); ++j) 
      if (x[i][j].c > 0) y[i][x[i][j].v] -= x[i][j].c;
    
    for (int i = 0; i < M; ++i) cout << y[z[i].first][z[i].second] << endl;
    
    return 0;
}
