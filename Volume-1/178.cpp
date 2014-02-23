#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N, i = 0, j = 2;
    cin >> N;
    while (true) {
        if ((i + 1) * j - 1 >= N) {
            cout << i << endl;
            break;
        }
        j += j;
        ++i;
    }
    return 0;
}
