#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int x[110][110];


int main() {
    int n, nn;
    cin >> n;
    nn = n;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) x[i][j] = (i-1) * n + j;
    
    int a = 1, b = n;
    while (n > 0) {
        if (n == 1) break;
        if (n == 2) {
            cout << nn << " " << x[a+1][a] << endl;
            cout << nn + 1 << " " << x[a][a] << " " << x[a+1][a+1] << endl;
            break;
        }
        if (n & 1) {
            cout << nn;
            for (int i = a; i <= b; i += 2) cout << " " << x[i][a] << " " << x[i][b];
            for (int j = a + 2; j <= b - 2; j += 2) cout << " " << x[a][j] << " " << x[b][j];
            cout << endl;
            nn += 2;
            cout << nn;
            for (int i = a + 1; i < b; i += 2) cout << " " << x[i][a] << " " << x[i][b];
            for (int j = a + 1; j < b; j += 2) cout << " " << x[a][j] << " " << x[b][j];
            cout << endl;
            nn += 2;
            ++a; --b;
            n -= 2;
        } else {
            cout << nn + 1;
            for (int i = a; i < b; i += 2) cout << " " << x[i][a];
            for (int i = a + 2; i < b; i += 2) cout << " " << x[a][i];
            for (int i = a + 1; i <= b; i += 2) cout << " " << x[b][i];
            for (int i = a + 1; i < b; i += 2) cout << " " << x[i][b];
            cout << endl;
            nn += 2;
            cout << nn + 1;
            for (int i = a + 1; i <= b; i += 2) cout << " " << x[i][a] << " " << x[a][i];
            for (int i = a + 2; i < b; i += 2) cout << " " << x[i][b] << " " << x[b][i];
            cout << endl;
            nn += 2;
            ++a; --b;
            n -= 2;
        }
    }

    return 0;
}
