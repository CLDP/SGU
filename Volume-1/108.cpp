#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int n, m;
int sum[10000];
int x[5010], y[5010];
int self[100];
int ans_num;
vector<int> ans;


int main() {
    for (int i = 1; i < 10000; ++i) sum[i] = i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        if (self[i % 100] != i / 100 + 1) ans.push_back(i);
        self[(i + sum[i / 10000] + sum[i % 10000]) % 100] 
           = (i + sum[i / 10000] + sum[i % 10000]) / 100 + 1;
        if (ans.size() == 100000) {
            for (int j = 0; j < m; ++j) {
                if (x[j] >= ans_num && x[j] < ans_num + 100000) {
                    y[j] = ans[x[j] - ans_num];
                }
            }
            ans_num += ans.size();
            ans.clear();
        }
    }
    
    for (int j = 0; j < m; ++j) {
        if (x[j] >= ans_num) {
            y[j] = ans[x[j] - ans_num];
        }
    }
    ans_num += ans.size();
    
    cout << ans_num << endl;
    for (int i = 0; i < m; ++i) {
        cout << y[i];
        if (i != m-1) 
            cout << " ";
        else
            cout << endl;
    }
    
    return 0;
}
