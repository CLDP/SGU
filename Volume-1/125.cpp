#include <cmath>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int x[5][5];
int y[5][5];

bool dfs2(int a, int b) {
    if (a == 3) {
        bool flag = true;
        int tmp;
        for (int i = 1; i <= 2; ++i)
         for (int j = 1; j <= 2; ++j) {
             tmp = (y[i-1][j] > y[i][j]) + (y[i+1][j] > y[i][j]) 
                 + (y[i][j-1] > y[i][j]) + (y[i][j+1] > y[i][j]);
             flag &= (tmp == x[i][j]);
             if (!flag) break;
         }
         
        return flag;
    }
    if (b == 3) return dfs2(a + 1, 1);
    for (int i = 0; i < 10; ++i) {
        y[a][b] = i;
        if (dfs2(a, b + 1)) return true;
    }
    return false;
}


bool dfs22() {
    for (int i = 0; i < 10; ++i) {
        y[2][2] = i;
        int c = (y[1][2] > y[2][2]) + (y[3][2] > y[2][2])
              + (y[2][1] > y[2][2]) + (y[2][3] > y[2][2]);
        if (c != x[2][2]) continue;
        c = (y[1][1] > y[1][2]) + (y[1][3] > y[1][2]) + (y[2][2] > y[1][2]);
        if (c != x[1][2]) continue;
        c = (y[1][1] > y[2][1]) + (y[2][2] > y[2][1]) + (y[3][1] > y[2][1]);
        if (c != x[2][1]) continue;
        c = (y[3][1] > y[3][2]) + (y[2][2] > y[3][2]) + (y[3][3] > y[3][2]);
        if (c != x[3][2]) continue;
        c = (y[1][3] > y[2][3]) + (y[2][2] > y[2][3]) + (y[3][3] > y[2][3]);
        if (c != x[2][3]) continue;
        return true;
    }
    return false;
}

bool dfs13() {
    for (int i = 0; i < 10; ++i) {
        y[1][3] = i;
        int c = (y[1][2] > y[1][3]) + (y[2][3] > y[1][3]);
        if (c != x[1][3]) continue;
        if (dfs22()) return true;
    }
    return false;
}

bool dfs33() {
    for (int i = 0; i < 10; ++i) {
        y[3][3] = i;
        int c = (y[3][2] > y[3][3]) + (y[2][3] > y[3][3]);
        if (c != x[3][3]) continue;
        if (dfs13()) return true;
    }
    return false;
}

bool dfs23() {
    for (int i = 0; i < 10; ++i) {
        y[2][3] = i;
        if (dfs33()) return true;
    }
    return false;
}

bool dfs32() {
    for (int i = 0; i < 10; ++i) {
        y[3][2] = i;
        int c = (y[3][2] > y[3][1]) + (y[2][1] > y[3][1]);
        if (c != x[3][1]) continue;
        if (dfs23()) return true;
    }
    return false;
}

bool dfs31() {
    for (int i = 0; i < 10; ++i) {
        y[3][1] = i;
        if (dfs32()) return true;
    }
    return false;
}

bool dfs21() {
    for (int i = 0; i < 10; ++i) {
        y[2][1] = i;
        int c = (y[2][1] > y[1][1]) + (y[1][2] > y[1][1]);
        if (c != x[1][1]) continue;
        if (dfs31()) return true;
    } 
    return false;
}

bool dfs12() {
    for (int i = 0; i < 10; ++i) {
        y[1][2] = i;
        if (dfs21()) return true;
    }
    return false;
}

bool dfs11() {
    for (int i = 0; i < 10; ++i) {
        y[1][1] = i;
        if (dfs12()) return true;
    }
    return false;
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) cin >> x[i][j];
    
    if (n == 1) {
        if (x[1][1] == 0) {
            cout << "0" << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    if (n == 2) {
        if (dfs2(1, 1)) {
            cout << y[1][1] << " " << y[1][2] << endl;
            cout << y[2][1] << " " << y[2][2] << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    if (n == 3) {
        if (dfs11()) {
            cout << y[1][1] << " " << y[1][2] << " " << y[1][3] << endl;
            cout << y[2][1] << " " << y[2][2] << " " << y[2][3] << endl;
            cout << y[3][1] << " " << y[3][2] << " " << y[3][3] << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    
    return 0;
}
