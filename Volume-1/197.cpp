#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxlen = 110; 
const int km = 10000;

class HP {
    public:
        int len, s[maxlen];
        HP() {(*this) = 0;};                  
        HP(int inte) {(*this) = inte;};   
        HP(const char *str) {(*this) = str;};  
        friend istream &operator >> (istream &cin, HP &x);
        HP operator = (int inte);
        HP operator = (const char *str);
        HP operator + (const HP &b);
        HP operator - (const HP &b);
        int Compare(const HP &b);
};

istream &operator >> (istream &cin, HP &x) {
    char p[maxlen];
    scanf("%s", p);
    x = p;
    return cin;
}

HP HP::operator = (const char *str) {
    len = strlen(str);
    int j;
    memset(s, 0, sizeof(s));
    for (int i = 0; i < len; ++i) {
        j = (len - i +3) / 4;
        s[j] = s[j]*10 + str[i] - '0';  
    } 
    len = (len + 3) / 4;
    return *this;
}

HP HP::operator = (int inte) {
    if (inte == 0) {
        len = 1;
        s[1] = 0;
        return (*this);
    }
    len = 0;
    while (inte > 0) {
        s[++len] = inte % km;
        inte /= km;
    }
    return (*this);
}

HP HP::operator + (const HP &b) {
    int i;
    HP c;
    c.s[1] = 0;
    for (i = 1; i <= len || i <= b.len || c.s[i]; ++i) {  
        if (i <= len) c.s[i] += s[i];                    
        if (i <= b.len) c.s[i] += b.s[i];        
        c.s[i+1] = c.s[i] / km; 
        c.s[i] %= km;
    }
    c.len = i-1;
    if (c.len == 0) c.len = 1;
    return c;
}

HP HP::operator - (const HP &b) {
    int i, j;
    HP c;
    for (i = 1, j = 0; i <= len; ++i) {
        c.s[i] = s[i] - j;
        if (i <= b.len) c.s[i] -= b.s[i];
        if (c.s[i] < 0) {
            j = 1;
            c.s[i] += km;
        } else j = 0;
    }
    c.len = len;
    while (c.len > 1 && !c.s[c.len]) c.len--;
    return c;
}

int HP::Compare(const HP &y) {
    if (len > y.len) return 1;
    if (len < y.len) return -1;
    int i = len;
    while ((i > 1) && (s[i] == y.s[i])) --i;
    if (s[i] == y.s[i]) return 0;
    return s[i] - y.s[i] > 0 ? 1 : -1;
}


int f[340][32][32], g[32], h[32];

int main() {
    HP N;
    int M, P;
    cin >> N >> M >> P;
    N = N - 1;
    int S = (1 << M);
    for (int i = 0; i < S; ++i)
     for (int j = 0; j < S; ++j) {
         bool flag = true;
         for (int k = 1; k < M; ++k) {
             int temp = bool(i & (1 << k)) + bool(j & (1 << k)) + 
                        bool(i & (1 << k - 1)) + bool(j & (1 << k - 1));
             flag &= (temp > 0 && temp < 4);
         }
         if (flag) f[0][i][j] = 1;
     }
    
    HP T[340];
    T[0] = 1;
    int L = 0;
    while (N.Compare(T[L]) == 1) {
        ++L;
        for (int i = 0; i < S; ++i)
         for (int j = 0; j < S; ++j)
          for (int k = 0; k < S; ++k)
           f[L][i][j] = (f[L][i][j] + f[L - 1][i][k] * f[L - 1][k][j]) % P;
        T[L] = T[L - 1] + T[L - 1];
    }
    
    for (int i = 0; i < S; ++i) g[i] = 1;
    while (N.Compare(0) == 1) {
        if (N.Compare(T[L]) == -1) {
            --L;
            continue;
        }
        N = N - T[L];
        memset(h, 0, sizeof(h));
        for (int i = 0; i < S; ++i)
         for (int j = 0; j < S; ++j) h[i] = (h[i] + f[L][i][j] * g[j]) % P;
        for (int i = 0; i < S; ++i) g[i] = h[i];
        --L;
    }
    
    int ans = 0;
    for (int i = 0; i < S; ++i) ans = (ans + g[i]) % P;
    cout << ans << endl;
    
    return 0;
}
