#include <iostream>
using namespace std;


int main() {
    long long n, ans = 1;
    cin >> n;
    while (n > 0) ans += n--;
    cout << ans << endl;
    return 0;
}
