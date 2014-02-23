#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 1;
    if ((N - 1) % 3 == 0) ans += 2;
    if ((N - 1) % 6 == 0) ++ans;
    if (N == 1) ans = 8;
    cout << ans << endl;
    return 0;
}
