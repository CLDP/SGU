#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 40010;

struct node {
    int x, y, n;
};

struct segment {
    int x, y1, y2, n;
};


int n, m, nn;
vector<node> z;
vector<segment> line;
int l[MAXN], r[MAXN], e[MAXN];


int make(int a, int b) {
    int k, mid = (a + b) >> 1;
    k = ++nn;
    if (a < b) {
        l[k] = nn + 1;
        make(a, mid);
        r[k] = nn + 1;
        make(mid + 1, b);
    } else {
        l[k] = r[k] = 0;
    }
    return 0;
}

int insert(int t, int a, int c, int d) {
    int mid = (c + d) >> 1;
    if (a == c && c == d) {
        e[t] = 1;
        return 0;
    }
    
    if (a <= mid) insert(l[t], a, c, mid);
    if (mid < a)  insert(r[t], a, mid + 1, d);
    e[t] = e[l[t]] + e[r[t]];
    return 0;
}

int Delete(int t, int a, int c, int d) {
    int mid = (c + d) >> 1;
    if (a == c && c == d) {
        e[t] = 0;
        return 0;
    }
    
    if (a <= mid) Delete(l[t], a, c, mid);
    if (mid < a)  Delete(r[t], a, mid + 1, d);
    
    e[t] = e[l[t]] + e[r[t]];
    return 0;
}

int cal(int t, int a, int b, int c, int d) {
    int mid = (c + d) >> 1;
    if (a <= c && d <= b) return e[t];
    
    int ret = 0;
    if (a <= mid) ret += cal(l[t], a, b, c, mid);
    if (mid < b) ret += cal(r[t], a, b, mid+1, d);
    return ret;
}

int find(int a) {
    if (l[a] != a) l[a] = find(l[a]);
    return l[a];
}

int Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (r[a] < r[b]) {
        l[a] = l[b];
    } else {
        l[b] = l[a];
    }
    r[a] += r[b];
    r[b] = r[a];
    return 0;
}

bool comparex(const node &a, const node &b) {
    if (a.x < b.x) return true;
    if (a.x == b.x) return a.y < b.y;
    return false;
}

bool comparey(const node &a, const node &b) {
    if (a.y < b.y) return true;
    if (a.y == b.y) return a.x < b.x;
    return false;
}

bool comparel(const segment &a, const segment &b) {
    return a.x < b.x;
}


int main() {
    int n;
    node p;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p.x, &p.y);
        p.n = i;
        z.push_back(p);
    }
    
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        l[i] = i;
        r[i] = 1;
    }
    
    int ans = 0;
    
    sort(z.begin(), z.end(), comparex);
    
    segment q;
    q.n = 0;
    for (int i = 0; i < n; i += 2) {
        if (z[i].x != z[i+1].x) {
            cout << 0 << endl;
            return 0;
        }
        q.x = z[i].x;
        q.y1 = z[i].y + 10000;
        q.y2 = z[i+1].y + 10000;
        line.push_back(q);
        ans += z[i+1].y - z[i].y;
        Union(z[i].n, z[i+1].n);
    }
    
    sort(z.begin(), z.end(), comparey);
    
    for (int i = 0; i < n; i += 2) {
        if (z[i].y != z[i+1].y) {
            cout << 0 << endl;
            return 0;
        }
        q.n = 1;
        q.x = z[i].x;
        q.y1 = z[i].y + 10000;
        line.push_back(q);
        q.n = 2;
        q.x = z[i+1].x;
        line.push_back(q);
        ans += z[i+1].x - z[i].x;
        Union(z[i].n, z[i+1].n);
    }
    
    int tmp = 0;
    for (int i = 0; i < n; ++i) tmp = max(tmp, r[i]);
    if (tmp != n) {
        cout << 0 << endl;
        return 0;
    }
    
    make(0, 20000);
    
    sort(line.begin(), line.end(), comparel);
    
    int len = line.size();
    tmp = 0;
    for (int i = 0; i < len; ++i) {
        if (line[i].n == 0) {
            tmp += cal(1, line[i].y1+1, line[i].y2-1, 0, 20000);
            if (tmp > 0) break;
        } else
        if (line[i].n == 1) {
            insert(1, line[i].y1, 0, 20000);
        } else {
            Delete(1, line[i].y1, 0, 20000);
        }
    }
    
    if (tmp > 0) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << ans << endl;
    
    return 0;
}
