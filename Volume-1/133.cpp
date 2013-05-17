#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, a, b;
    vector<pair<int, int> > x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x.push_back(make_pair(a, b));
    }
    sort(x.begin(), x.end());
    
    int ans = 0, right = x[0].second;
    for (int i = 1; i < n; ++i) {
        if (x[i].second < right) ++ans;
        if (x[i].second > right) right = x[i].second;
    }
    
    cout << ans << endl;
    
    return 0;
}
