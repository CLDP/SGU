#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 65540;
const int MAXS = MAXN * 2;

int x[MAXN], f[MAXS];
map<int, int> C;

int update(int a) {
    for (int i = a; i < MAXS; i += (i & -i)) ++f[i];
    return 0;
}

int query(int a) {
    int ans = 0;
    for (int i = a; i > 0; i -= (i & -i)) ans += f[i];
    return ans;
}


int main() {
    int N, M = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        C[x[i]] = 0;
    }
    for (map<int, int>::iterator i = C.begin(); i != C.end(); ++i) i->second = ++M;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += query(M) - query(C[x[i]]);
        update(C[x[i]]);
    }
    cout << ans << endl;
    
    return 0;
}
