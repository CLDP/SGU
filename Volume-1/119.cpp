#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > ans;

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}


int main() {
    int n, a, b, r;
    cin >> n >> a >> b;
    r = n / gcd(gcd(a, b), n);
    for (int i = 0; i < r; ++i) ans.push_back(make_pair(a * i % n, b * i % n));
    sort(ans.begin(), ans.end());
    cout << r << endl;
    for (int i = 0; i < r; ++i) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
