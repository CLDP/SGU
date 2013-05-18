#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

vector<pair<int, int> > x;
int win[MAXN], lose[MAXN];


int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        x.push_back(make_pair(-a, i + 1));
        sum += a;
    }
    
    sum /= 2;
    sort(x.begin(), x.end());
    
    int j = 0;
    for (int i = 1; i <= sum; ++i) {
        if (x[j].first == -1) {
            lose[i] = x[j].second;
            ++x[j++].first;
        }
        win[i] = x[j].second;
        ++x[j].first;
    }
    
    for (int i = 1; i <= sum; ++i) {
        if (lose[i]) continue;
        if (!x[j].first) ++j;
        lose[i] = x[j].second;
        ++x[j].first;
    }
    
    cout << sum << endl;
    for (int i = 1; i <= sum; ++i) cout << win[i] << " " << lose[i] << endl;
    
    return 0;
}

