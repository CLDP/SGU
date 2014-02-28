#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXL = 270;
//0:~   1:&   2:|   3:>   4:=   5:(
const bool priority[6][6] = {{0,0,0,0,0,0},
                             {1,1,0,0,0,0},
                             {1,1,1,0,0,0},
                             {1,1,1,0,0,0},
                             {1,1,1,1,0,0},
                             {0,0,0,0,0,0}};

int n, d;
bool g[MAXN][MAXN];

struct H {
    bool v[MAXN];
    H() {}
    H(int val) { memset(v, val, sizeof(v)); }
    bool operator == (H const &B) const {
        for (int i = 0; i < n; ++i)
         if (v[i] != B.v[i]) return false;
        return true;
    }
} h[MAXN];


void dfsh(int u) {
    static H A;
    if (u == n) {
        h[d++] = A;
        return;
    }
    dfsh(u + 1);
    int i;
    for (i = 0; i < u; ++i)
     if (A.v[i] && (g[u][i] || g[i][u])) return;
    A.v[i] = 1;
    dfsh(u + 1);
    A.v[i] = 0;
}

H max(H A) {
    for (int i = 0; i < n; ++i)
     if (A.v[i])
      for (int j = 0; j < n; ++j)
       if (A.v[j] && i != j && g[i][j]) {
           A.v[i] = 0;
           break;
       }
    return A;
}

H implication(const H &A, H B) {
    for (int i = 0; i < n; ++i)
     if (B.v[i])
      for (int j = 0; j < n; ++j)
       if (A.v[j] && g[i][j]) {
           B.v[i] = 0;
           break;
       }
    return B;
}

H conjunction(H A, const H &B) {
    for (int i = 0; i < n; ++i)
     if (B.v[i]) A.v[i] = 1;
    return max(A);
}

H disjunction(H A, const H &B) {
    H C(0);
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0; j < n; ++j)
         if (A.v[j] && g[i][j]) break;
        if (j == n) continue;
        for (j = 0; j < n; ++j)
         if (B.v[j] && g[i][j]) break;
        if (j < n) C.v[i] = 1;
    }
    return max(C);
}


int vim[MAXN][MAXN], vand[MAXN][MAXN], vor[MAXN][MAXN];
int topo, op[MAXL], topn, num[MAXL];

void pop() {
    int t = op[topo];
    if (t == 4) {
        int c = 1;
        while (op[topo - c] == 4) ++c;
        topo -= c;
        int b = topn - c, res = vand[vim[num[b]][num[b + 1]]][vim[num[b + 1]][num[b]]];
        for (b = b + 1; b < topn; ++b)
         res = vand[res][vand[vim[num[b]][num[b + 1]]][vim[num[b + 1]][num[b]]]];
        num[topn -= c] = res;
        return;
    }
    --topo;
    if (t) {
        --topn;
        if (t == 1)
            num[topn] = vand[num[topn]][num[topn + 1]];
        else 
        if (t == 2)
            num[topn] = vor[num[topn]][num[topn + 1]];
        else 
            num[topn] = vim[num[topn]][num[topn + 1]];
    } else {
        num[topn] = vim[num[topn]][1];
    }
}

int e[26];
char s[MAXL];

bool check() {
    topn = topo = 0;
    for (char *p = s; *p; ++p) {
        if (isblank(*p)) continue;
        if (isupper(*p))
            num[++topn] = e[*p - 'A'];
        else
        if (isdigit(*p))
            num[++topn] = !(*p - '0');
        else 
        switch (*p) {
            case ')' :
                while (op[topo] != 5) pop();
                --topo;
                break;
            default  :
                int sign;
                switch (*p) {
                    case '~' : sign = 0; break;
                    case '&' : sign = 1; break;
                    case '|' : sign = 2; break;
                    case '>' : sign = 3; break;
                    case '=' : sign = 4; break;
                    default  : sign = 5; break;
                }
                while (topo && priority[sign][op[topo]]) pop();
                op[++topo] = sign;
        }
    }
    while (topo) pop();
    return !num[1];
}

bool dfs(int u) {
    while (u < 26 && e[u] == -1) ++u;
    if (u == 26) return check();
    while (e[u] < d) {
        if (!dfs(u + 1)) return false;
        ++e[u];
    }
    e[u] = 0;
    return true;
}


int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a - 1][b - 1] = true;
    }
    for (int k = 0; k < n; ++k)
     for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
       if (g[i][k] && g[k][j]) g[i][j] = true;
    for (int i = 0; i < n; ++i) g[i][i] = true;
    
    // Pre-calculate all possibility
    dfsh(0);
    swap(h[1], *find(h + 1, h + d, max(H(1))));
    for (int i = 0; i < d; ++i)
     for (int j = 0; j < d; ++j) {
         vim[i][j] = find(h, h + d, implication(h[i], h[j])) - h;
         vand[i][j] = find(h, h + d, conjunction(h[i], h[j])) - h;
         vor[i][j] = find(h, h + d, disjunction(h[i], h[j])) - h;
     }
    
    // Process
    scanf("%d\n", &m);
    for(int i = 0; i < m; ++i) {
        gets(s);
        memset(e, -1, sizeof(e));
        for (char *p = s; *p; ++p)
         if (isupper(*p))
             e[*p - 'A'] = 0;
         else 
         if (*p == '>')
             *(p - 1) = ' ';
        printf(dfs(0) ? "valid\n" : "invalid\n");
    }
    
    return 0;
}
