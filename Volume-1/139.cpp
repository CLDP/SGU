#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x[4][4];

int main() {
    int sum = 0;
    for (int i = 0; i < 4; ++i)
     for (int j = 0; j < 4; ++j) {
         cin >> x[i][j];
         if (!x[i][j]) {
             x[i][j] = 16;
             sum += 6 - i - j;
         }
     }
    
    while (true) {
        bool find = false;
        for (int i = 0; i < 4; ++i)
         for (int j = 0; j < 4; ++j) 
          if (i * 4 + j + 1 != x[i][j]) {
              swap(x[i][j], x[(x[i][j] - 1) / 4][(x[i][j] - 1) % 4]);
              ++sum;
              find = true;
          }
        
        if (!find) break;
    }
    
    if (sum & 1) 
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    
    return 0;
}

