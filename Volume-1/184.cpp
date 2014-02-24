#include <iostream>
using namespace std;

int main() {
    int A, B, C, a, b, c;
    cin >> A >> B >> C >> a >> b >> c;
    cout << min(min(A / a, B / b), C / c) << endl;
    return 0;
}
