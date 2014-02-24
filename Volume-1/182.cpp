#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2050;

char x[MAXN];
bool y[10], z[10];
bool ans[1024][10];
int ansT;
vector<int> C;


bool check() {
    stack<bool> S;
    int M = C.size();
    for (int i = 0; i < M; ++i) {
        if (C[i] < 10) {
            if (C[i] >= 0)
                S.push(z[C[i]]);
            else 
                S.push(1);
        } else {
            bool a = S.top();  S.pop();
            bool b = S.top();  S.pop();
            switch (C[i]) {
                case 20 : S.push(a != b); break;
                case 19 : S.push(a & b);  break;
                case 18 : S.push(a | b);  break;
                case 17 : S.push(a == b); break;
                case 16 : S.push(a | !b); break;
                case 15 : S.push(a != b); break;
            }
        }
    }
    return S.top();
}


int dfs(int a) {
    if (a == 10) {
        if (check()) {
            for (int i = 0; i < 10; ++i) ans[ansT][i] = z[i];
            ++ansT;
        }
        return 0;
    }
    if (!y[a]) {
        dfs(a + 1);
        return 0;
    }
    z[a] = false;
    dfs(a + 1);
    z[a] = true;
    dfs(a + 1);
    return 0;
}


int main() {
    scanf("%s", x);
    int N = strlen(x);
    stack<int> S;
    // ! (1 XOR) 20,  & 19, || 18, <=> 17, =>16, # 15
    for (int i = 0; i < N; ++i) {
        if (x[i] >= 'a' && x[i] <= 'j') y[x[i] - 'a'] = true;
        if (x[i] >= 'a' && x[i] <= 'j') {
            C.push_back(x[i] - 'a');
            continue;
        }
        if (x[i] == '!') {
            C.push_back(-1);
            S.push(20);
            continue;
        }
        if (x[i] == '&') {
            while (!S.empty() && S.top() >= 19) {
                C.push_back(S.top());
                S.pop();
            }
            S.push(19);
            continue;
        }
        if (x[i] == '|') {
            while (!S.empty() && S.top() != -1) {
                C.push_back(S.top());
                S.pop();
            }
            S.push(18);
            ++i;
            continue;
        }
        if (x[i] == '<') {
            while (!S.empty() && S.top() != -1) {
                C.push_back(S.top());
                S.pop();
            }
            S.push(17);
            i += 2;
            continue;
        }
        if (x[i] == '=') {
            while (!S.empty() && S.top() != -1) {
                C.push_back(S.top());
                S.pop();
            }
            S.push(16);
            ++i;
            continue;
        }
        if (x[i] == '#') {
            while (!S.empty() && S.top() != -1) {
                C.push_back(S.top());
                S.pop();
            }
            S.push(15);
            continue;
        }
        if (x[i] == '(') {
            S.push(-1);
            continue;
        }
        if (x[i] == ')') {
            while (S.top() != -1) {
                C.push_back(S.top());
                S.pop();
            }
            S.pop();
            continue;
        }
    }
    while (!S.empty()) {
        C.push_back(S.top());
        S.pop();
    }
    
    dfs(0);
    
    int je = 0;
    for (int j = 0; j < 10; ++j)
     if (y[j]) je = j;
    
    for (int i = 0; i < ansT; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!y[j]) continue;
            if (ans[i][j]) printf("%c", j + 'a'); else printf("!%c", j + 'a');
            if (j != je) printf("&");
        }
        if (i != ansT - 1) printf("||");
    }
    if (ansT == 0) printf("%c&!%c", je + 'a', je + 'a');
    printf("\n");

    return 0;
}
