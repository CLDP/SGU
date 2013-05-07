#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> prime, sprime;
int f[10010], fa[10010];

bool check(int a) {
    if (a == 1) return false;
    int b = sqrt(a);
    for (int i = 2; i <= b; ++i)
     if (a / i * i == a) return false;
    return true;
}


int main() {
    for (int i = 2; i < 10000; ++i) {
        if (!check(i)) continue;
        prime.push_back(i);
        if (check(prime.size())) sprime.push_back(i);
    }
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) f[i] = n;
    for (int i = 0; i < sprime.size(); ++i)
     for (int j = 0; j <= n - sprime[i]; ++j) 
      if (f[j+sprime[i]] > f[j] + 1) {
          f[j+sprime[i]] = f[j] + 1;
          fa[j+sprime[i]] = j;
      }
    
    if (f[n] == n) {
        cout << 0 << endl;
        return 0;
    }
    cout << f[n] << endl;
    vector<int> ans;
    while (n > 0) {
        ans.push_back(fa[n] - n);
        n = fa[n];
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; ++i) cout << -ans[i] << " ";
    cout << -ans[ans.size() - 1] << endl;
        
    return 0;
}
