#include <iostream>
#include <cmath>
#include <set>
#include <cstdio>
using namespace std;

const int MAXN = 15010;

int N;
int x[MAXN], y[MAXN], z[MAXN], s[MAXN];

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        s[i] = s[i - 1] + x[i];
    }
    
    int ans = z[1];
    set<pair<int, int> > S;
    for (int i = 2; i <= N; ++i) {
        if (s[i] > y[i]) {
            S.insert(make_pair(s[i] - y[i], i));
        } else {
            ans += z[i];
        }
    }
    
    int temp = ans;
    for (int i = 1; i < N; ++i) {
        temp -= z[i];
        while (!S.empty() && S.begin()->first <= s[i]) {
            temp += z[S.begin()->second];
            S.erase(S.begin());
        }
        if (temp < ans) ans = temp;
    }
    
    temp = z[1];
    S.clear();
    set<int> C;
    C.insert(1);
    for (int i = 2; i <= N; ++i) {
        if (s[i] > y[i]) {
            S.insert(make_pair(s[i] - y[i], i));
        } else {
            temp += z[i];
            C.insert(i);
        }
    }
    
    if (temp == ans) {
        for (set<int>::iterator i = C.begin(); i != C.end(); ++i) printf("%d\n", *i);
        return 0;
    }
    
    for (int i = 1; i < N; ++i) {
        temp -= z[i];
        while (!S.empty() && S.begin()->first <= s[i]) {
            temp += z[S.begin()->second];
            C.insert(S.begin()->second);
            S.erase(S.begin());
        }
        C.erase(C.begin());
        if (temp == ans) {
            for (set<int>::iterator i = C.begin(); i != C.end(); ++i) printf("%d\n", *i);
            break;
        }
    }
    
    return 0;
}
