#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 500005;

char s[MAXN];
bool z[1 << 20];
int ans[20];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", s);
    int len = floor(log(N)/ log(2)) + 1;
    int total = 1 << (len + 1);
    for (int i = 0; i < N; ++i) {
        int num = 1;
        for (int j = 0; j < len && i + j < N; ++j) {
            if (s[i + j] == 'a')
                num <<= 1;
            else
                num = num << 1 | 1;
            z[num] = true;
        }
    }
    
    int s1 = -1;
    for (int i = 2; i < total; ++i)
     if (!z[i]) {
         s1 = i;
         break;
     }
    
    int ansL = floor(log(s1)/ log(2));
    int j = ansL;
    while (s1 > 1) {
        ans[j--] = s1 & 1;
        s1 >>= 1;
    }
    printf("%d\n", ansL);
    for (int i = 1; i <= ansL; ++i) printf("%c", ans[i] + 'a');
    printf("\n");
    
    return 0;
}
