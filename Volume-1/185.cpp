#include <vector>
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 401;
const int INF = 1000000000;


int N, d[MAXN], f[MAXN];
bool z[MAXN];
vector<pair<int, int> > x[MAXN];


int SPFA() {
    for (int i = 1; i <= N; ++i) {
        d[i] = INF;
        z[i] = false;
    }
    
    d[1] = 0;
    z[1] = true;
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int a = que.front();
        que.pop();
        for (int i = 0; i < x[a].size(); ++i) {
            if (d[x[a][i].first] > d[a] + x[a][i].second) {
                d[x[a][i].first] = d[a] + x[a][i].second;
                f[x[a][i].first] = a;
                if (!z[x[a][i].first]) {
                    z[x[a][i].first] = true;
                    que.push(x[a][i].first);
                }
            }
        }
        z[a] = false;
    }
    return 0;
}

int get_ans(vector<int> &ans) {
    int a, b = N;
    ans.push_back(b);
    while (b != 1) {
        a = f[b];
        for (int i = 0; i < x[a].size(); ++i) {
            if (x[a][i].first != b) continue;
            x[a].erase(x[a].begin() + i);
            break;
        }
        for (int i = 0; i < x[b].size(); ++i) {
            if (x[b][i].first != a) continue;
            x[b][i].second = -x[b][i].second;
            break;
        }
        b = a;
        ans.push_back(b);
    }
    return 0;
}

int change(vector<int> &A, vector<int> &B) {
    vector<int> xa(N + 1, -1), xb(N + 1, -1);
    int SA = A.size(), SB = B.size();
    for (int i = 1; i < SA - 1; ++i) xa[A[i]] = i;
    for (int j = 1; j < SB - 1; ++j) xb[B[j]] = j;
    
    for (int i = 2; i < N; ++i) {
        if (xa[i] == -1 || xb[i] == -1) continue;
        int a = xa[i], b = xb[i], c = 0;
        while (a + c < SA && b - c >= 0 && A[a + c] == B[b - c]) ++c;
        if (c == 1) continue;
        vector<int> AA, BB;
        for (int j = 0; j < a; ++j) AA.push_back(A[j]);
        for (int j = b; j < SB; ++j) AA.push_back(B[j]);
        for (int j = 0; j <= b - c; ++j) BB.push_back(B[j]);
        for (int j = a + c - 1; j < SA; ++j) BB.push_back(A[j]);
        A = AA;
        B = BB;
        return true;
    }
    return false;
}



int print(vector<int> &ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i == ans.size() - 1) cout << endl; else cout << " ";
    }
    return 0;
}


int main() {
    int M, a, b, c;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        x[a].push_back(make_pair(b, c));
        x[b].push_back(make_pair(a, c));
    }
    
    SPFA();
    if (d[N] == INF) {
        cout << "No solution" << endl;
        return 0;
    }
    
    int shortest = d[N];
    vector<int> ans1;
    get_ans(ans1);
    SPFA();
    if (d[N] != shortest) {
        cout << "No solution" << endl;
        return 0;
    }
    vector<int> ans2;
    get_ans(ans2);
    
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    
    while (true) {
        if (!(change(ans1, ans2))) break;
    }
    
    print(ans1);
    print(ans2);
    
    return 0;
}
