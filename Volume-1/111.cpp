#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 1010; 

class HP {
public:
    int len, s[MAXL];
    HP() {(*this) = 0;};
    HP(int inte) {(*this) = inte;}; 
    HP(const char *str) {(*this) = str;};
    friend istream &operator >> (istream &cin, HP &x);
    friend ostream &operator << (ostream &cout, const HP &x);
    HP operator = (int inte);
    HP operator = (const char *str);
    HP operator * (const HP &b);
    HP operator + (const HP &b);
    int Compare(const HP &b);
};

istream &operator >> (istream &cin, HP &x) {
    char p[MAXL];
    scanf("%s", p);
    x = p;
    return cin;
}

ostream &operator << (ostream &cout, const HP &x) {
    for (int i = x.len; i >= 1; --i) printf("%d",x.s[i]);
    return cout;
}

HP HP::operator = (const char *str) {
    len = strlen(str);
    for (int i = 1; i <= len; ++i) s[i] = str[len-i] - '0';
    return *this;
}

HP HP::operator = (int inte) {
    if (inte == 0) {
        len = 1;
        s[1] = 0;
        return (*this);
    }
    for (len = 0; inte > 0;) {
        s[++len] = inte % 10;
        inte /= 10;
    }
    return (*this);
}

HP HP::operator * (const HP &b) {
    int i, j;
    HP c;
    c.len = len + b.len;
    for (i = 1; i <= c.len; ++i) c.s[i] = 0;
    for (i = 1; i <= len; ++i) 
     for (j = 1; j <= b.len; ++j)
      c.s[i+j-1] += s[i]*b.s[j];
    for (i = 1; i < c.len; ++i) {
        c.s[i+1] += c.s[i] / 10;
        c.s[i] %= 10;
    }
    while (c.s[i]) {
        c.s[i+1] = c.s[i] / 10;
        c.s[i] %= 10; 
        ++i;
    }
    while (i > 1 && !c.s[i]) i--;
    c.len = i;
    return c;
}

int HP::Compare(const HP &y) {
    if (len > y.len) return 1;
    if (len < y.len) return -1;
    int i = len;
    while ((i > 1) && (s[i] == y.s[i])) --i;
    return s[i] - y.s[i];
}

int main() {
    HP n, m;
    // The data for this problem is much smaller than 10^1000
    // Otherwise, both this one and binary search would TLE
    cin >> n;
    m.len = (n.len + 1) / 2;
    int len = m.len;
    while (len > 0) {
        m.s[len] = 4;
        // One small optimization
        if (n.Compare(m * m) >= 0)
            m.s[len] = 5;
        else
            m.s[len] = 1;
        while (n.Compare(m * m) >= 0) ++m.s[len];
        --m.s[len];
        --len;
    }
    cout << m << endl;
    return 0;
}
