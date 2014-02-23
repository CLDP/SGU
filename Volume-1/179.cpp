#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char x[10010];


int main() {
    scanf("%s", x);
    int N = strlen(x);
    int L = 0, R = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (x[i] == '(' && R - L - 1 >= 1) {
            x[i] = ')';
            for (int k = 1; k <= L + 1; ++k) x[i + k] = '(';
            for (int k = 1; k <= R - 1; ++k) x[N - k] = ')';
            cout <<x << endl;
            return 0;
        }
        if (x[i] == '(') ++L; else ++R;
    }
    cout << "No solution" << endl;
    
    return 0;
}
