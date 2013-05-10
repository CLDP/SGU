#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    long long a = 1, b = 0, c = 1;
    for (int i = 2; i <= n; ++i) {
        b = a + b;
        swap(a, b);
        c += a;
    }
    
    cout << c << endl;
    
    return 0;
}
