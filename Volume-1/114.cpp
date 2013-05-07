#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int, int> > x;


int main() {
    int n, a, b, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x.push_back(make_pair(a, b));
        sum += b;
    }
    sort(x.begin(), x.end());
    a = 0;
    for (int i = 0; i < n; ++i) {
        a += x[i].second;
        if (a >= sum / 2) {
            cout << x[i].first << endl;
            break;
        }
    }
    return 0;
}
