#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int ANS[14] = {0, 1, 2, 5, 14, 47, 189, 891, 4815, 29547, 203173, 1548222, 12966093, 118515434};

int main() {
    int N;
    cin >> N;
    cout << ANS[N] << endl;
    return 0;
}
