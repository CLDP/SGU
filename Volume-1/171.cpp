#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

struct student {
    int p, w, id;
    student(int _p, int _w, int _id) : p(_p), w(_w), id(_id) {}
    bool operator < (student const &B) const {
        if (w != B.w) return w > B.w;
        return p < B.p;
    }
};

int X[101], Q[101], P[16010], W[16010], A[16010];


int main() {
    int K, N = 0;
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &X[i]);
        N += X[i];
    }
    for (int i = 0; i < K; ++i) scanf("%d", &Q[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &P[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &W[i]);
    vector<student> C;
    for (int i = 0; i < N; ++i) C.push_back(student(P[i], W[i], i));
    sort(C.begin(), C.end());
    
    for (int i = 0; i < N; ++i) {
        int pos = -1, temp = -1;
        for (int j = 0; j < K; ++j) {
            if (X[j] == 0 || Q[j] >= C[i].p) continue;
            if (Q[j] > temp) {
                temp = Q[j];
                pos = j;
            }
        }
        if (pos != -1) --X[pos];
        A[C[i].id] = pos;
    }
    
    for (int i = 0; i < N; ++i) {
        if (A[i] != -1) {
            cout << A[i] + 1;
        } else {
            for (int j = 0; j < K; ++j) {
                if (X[j] == 0) continue; 
                cout << j + 1;
                --X[j];
                break;
            }
        }
        if (i == N - 1) cout << endl; else cout << " ";
    }
    
    return 0;
}
