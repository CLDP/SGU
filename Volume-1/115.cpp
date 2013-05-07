#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<pair<int, int> > x;


int main() {
    int n, m, a = 0;
    cin >> n >> m;
    if (m > 12 || m < 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (n > DAY[m-1] || n < 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < m - 1; ++i) a += DAY[i];
    a += n;
    cout << (a - 1) % 7 + 1 << endl;
    return 0;
}
