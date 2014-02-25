#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int l[20], v[20], f[20];


int main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i)
     for (int j = i + 1; j < n; ++j) 
      if (v[i] * v[j] < 0) {
          int dist = (l[i] - l[j]) * (v[j] > 0 ? 1 : -1);
          if (dist < 0) dist += 1000;
          int total = t * (abs(v[i]) + abs(v[j])) - dist;
          int times = (total >= 0 ? 1 + total / 1000 : 0);
          f[i] += times; 
          f[j] += times;
      }
    for (int i = 0; i < n; ++i) cout << f[i] << " ";
    cout << endl;
    return 0;
}
