#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

// My first solution got MLE......
// The array should be this small.
long long f[10][1 << 9];

int dp(int i, int j, int opt1, int opt2, int u1, int u2) {
     if (j == m){
         if (!u1 && !u2) f[i + 1][opt2] += f[i][opt1]; 
         return 0;
     }
     
     if (!u2) {
         if (!u1) {
             dp(i, j + 1, opt1 << 1, (opt2 << 1) + 1, 0, 0); 
             dp(i, j + 1, opt1 << 1, (opt2 << 1) + 1, 1, 0);
             dp(i, j + 1, opt1 << 1, (opt2 << 1) + 1, 0, 1);
         }
         dp(i, j + 1, (opt1 << 1) + 1 - u1, (opt2 << 1) + 1, 0, 1);
         dp(i, j + 1, (opt1 << 1) + 1 - u1, (opt2 << 1) + 1, 1, 1);
     }
     
     if (!u1) dp(i, j + 1, opt1 << 1, (opt2 << 1) + u2, 1, 1);
     dp(i, j + 1, (opt1 << 1) + 1 - u1, (opt2 << 1) + u2, 0, 0);
     
     return 0;
}

int main() {
    cin >> n >> m;
    f[0][(1 << m) - 1] = 1;
    
    for (int i = 0; i < n; ++i) dp(i, 0, 0, 0, 0, 0);
    
    cout << f[n][(1 << m) - 1] << endl;
    
    return 0;
}
