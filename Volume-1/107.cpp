#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    if (n < 9) {
        cout << 0 << endl;
    } else 
    if (n == 9) {
        cout << 8 << endl;
    } else {
        cout << 72;
        while (n > 10) {
            printf("0");
            --n;
        }
        cout << endl;
    }
    
    return 0;
}
