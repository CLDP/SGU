#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 2010;

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
        HP operator + (const HP &b);
        HP operator - (const HP &b);
        HP operator / (const int &b);
        int operator % (const int &b);
};

HP HP::operator = (const char *str) {
    len = strlen(str);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < len; ++i) s[len - i] = str[i] - '0';
    return *this;
}

istream &operator >> (istream &cin, HP &x) {
    char p[MAXL];
    scanf("%s", p);
    x = p;
    return cin;
}

ostream &operator << (ostream &cout, const HP &x) {
    for (int i = x.len; i >= 1; --i) printf("%d", x.s[i]);
    return cout;
}

HP HP::operator = (int inte) {
    if (inte == 0) {
        len = 1;
        s[1] = 0;
        return (*this);
    }
    len = 0;
    while (inte > 0) {
        s[++len] = inte % 10;
        inte /= 10;
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
        c.s[i+1] = c.s[i] / 10; 
        c.s[i] %= 10;
    }
    c.len = i - 1;
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
            c.s[i] += 10;
        } else j = 0;
    }
    c.len = len;
    while (c.len > 1 && !c.s[c.len]) c.len--;
    return c;
}

HP HP::operator / (const int &b) {
    HP c;
    int d = 0;
    for (int i = len; i > 0; --i) {
        d = d * 10 + s[i];
        c.s[i] = d / b;
        d %= b;
    }
    c.len = len;
    while ((c.len > 1) && (c.s[c.len] == 0)) --c.len;
    return c;
}

int HP::operator % (const int &b) {
    int d = 0;
    for (int i = len; i > 0; --i) {
        d = d * 10 + s[i];
        d %= b;
    }
    return d;
}


int main() {
    HP N;
    cin >> N;
    int K = N % 4;
    if (K == 0) {
        cout << N / 2 - 1 << endl;
    } else
    if (K == 2) {
        cout << N / 2 - 2 << endl;
    } else {
        cout << N / 2 << endl;
    }

    return 0;
}
