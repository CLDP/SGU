#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 310;
const int INF = 100000000;


struct node {
    bool blue;
    int s, a, b;
    // Start time, blue time, purple time
};


int s, t, n, m;
int x[MAXN][MAXN];
node y[MAXN];
int d[MAXN], f[MAXN];
bool z[MAXN];

int get(int used, int from, int to) {
    if (x[from][to] == 0) return INF;
    node a = y[from], b = y[to];
    a.s -= (used % (a.a + a.b));
    b.s -= (used % (b.a + b.b));
    while (a.s <= 0) a.s += (a.a + a.b);
    while (b.s <= 0) b.s += (b.a + b.b);
    
    if (a.blue && a.s > a.a) {
        a.s -= a.a;
        a.blue = false;
    } 
    if (!a.blue && a.s > a.b) {
        a.s -= a.b;
        a.blue = true;
    }
    if (b.blue && b.s > b.a) {
        b.s -= b.a;
        b.blue = false;
    }
    if (!b.blue && b.s > b.b) {
        b.s -= b.b;
        b.blue = true;
    }
    used += x[from][to];
    // No waiting needed
    if (a.blue == b.blue) return used;
    // Only need to change once
    if (a.s != b.s) return used + min(a.s, b.s);
    // Simultaneously change to the other light
    used += a.s;
    a.s = a.blue ? a.b : a.a;
    b.s = b.blue ? b.b : b.a;
    a.blue = !a.blue;
    b.blue = !b.blue;
    if (a.s != b.s) return used + min(a.s, b.s);
    // Simultaneously change to the other light again
    used += a.s;
    a.s = a.blue ? a.b : a.a;
    b.s = b.blue ? b.b : b.a;
    a.blue = !a.blue;
    b.blue = !b.blue;
    if (a.s != b.s) return used + min(a.s, b.s);
    // This line would not work forever
    return INF;
}


int main() {
    cin >> s >> t >> n >> m;
    for (int i = 1; i <= n; ++i) {
        char p;
        cin >> p >> y[i].s >> y[i].a >> y[i].b;
        if (p == 'B')
            y[i].blue = true;
        else
            y[i].blue = false;
    }
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x[a][b] = c;
        x[b][a] = c;
    }
    
    for (int i = 1; i <= n; ++i) d[i] = INF;
    d[s] = 0;
    
    while (true) {
        int p = INF, q = -1;
        for (int i = 1; i <= n; ++i) 
         if (!z[i] && d[i] < p) {
             p = d[i];
             q = i;
         }
        
        if (p == INF) break;
        
        z[q] = true;
        for (int i = 1; i <= n; ++i) {
            int time = get(p, q, i);
            if (time < d[i]) {
                d[i] = time;
                f[i] = q;
            }
        }
    }
    
    if (d[t] == INF) {
        cout << 0 << endl;
        return 0;
    }
    cout << d[t] << endl;
    
    vector<int> ans;
    while (t != s) {
        ans.push_back(t);
        t = f[t];
    }
    
    cout << s;
    for (int i = ans.size() - 1; i >= 0; --i) cout << " " << ans[i];
    cout << endl;
    
    return 0;
}
