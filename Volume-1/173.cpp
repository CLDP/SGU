#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 55;
const int MAX_LEN = 210;

int N, M, K, L;
int D[15], S[15];
int mtx_equ[MAX_LEN][MAX_SIZE];
int vec_res[MAX_LEN], vec_A[MAX_LEN], vec_ans[MAX_SIZE];
int mtx_base[MAX_SIZE][MAX_SIZE], mtx_ans[MAX_SIZE][MAX_SIZE], mtx_tmp[MAX_SIZE][MAX_SIZE];


void matrix_multiply(int num_tot) {
    bool flag = 0;
    memset(mtx_base, 0, sizeof(mtx_base));
    for (int i = 1; i < K; ++ i) {
        mtx_base[i][1] = vec_A[i];
        mtx_base[i][i + 1] = 1;
    }
    mtx_base[K][1] = 1;
    
    while (num_tot) {
        if (num_tot & 1) {
            if (!flag) {
                for (int i = 1; i <= K; ++i) 
                 for (int j = 1; j <= K; ++j) mtx_ans[i][j] = mtx_base[i][j];
                flag = 1;
            } else {
                for (int i = 1; i <= K; ++i)
                 for (int j = 1; j <= K; ++j) mtx_tmp[i][j] = 0;
                for (int i = 1; i <= K; ++i) 
                 for (int j = 1; j <= K; ++j) 
                  for (int k = 1; k <= K; ++k) {
                      mtx_tmp[i][j] += mtx_base[i][k] * mtx_ans[k][j];
                      mtx_tmp[i][j] &= 1;
                  }
                for (int i = 1; i <= K; ++i) 
                 for (int j = 1; j <= K; ++j) mtx_ans[i][j] = mtx_tmp[i][j];
            }
        }
        for (int i = 1; i <= K; ++i) 
         for (int j = 1; j <= K; ++j) mtx_tmp[i][j] = 0;
        for (int i = 1; i <= K; ++i) 
         for (int j = 1; j <= K; ++j) 
          for (int k = 1; k <= K; ++k) {
              mtx_tmp[i][j] += mtx_base[i][k] * mtx_base[k][j];
              mtx_tmp[i][j] &= 1;
          }
        for (int i = 1; i <= K; ++i) 
         for (int j = 1; j <= K; ++j) mtx_base[i][j] = mtx_tmp[i][j];
        
        num_tot >>= 1;
    }
}


int main() {
    // Input and set equations
    scanf("%d%d%d%d", &N, &M, &K, &L);
    for(int i = 1; i <= M; ++i) scanf("%d%d", &S[i], &D[i]);
    for(int i = 1; i <= L; ++i) {
        char s[MAX_SIZE], t[MAX_SIZE];
        scanf("%s%s", s, t);
        for (int j = 1; j < K; ++j) mtx_equ[i][j]= s[j] - '0';
        vec_res[i] = (s[0] != t[K - 1]);
    }
    
    // Gaussian Elimination, find A
    for (int i = 1; i < K; ++i) {
        int tmp;
        for (int j = i; j <= L; ++j)
         if (mtx_equ[j][i]) {
             tmp = j; 
             break;
         }
        swap(vec_res[i], vec_res[tmp]);
        for (int j = 1; j < K; ++j) swap(mtx_equ[i][j], mtx_equ[tmp][j]);
        for (int j = i + 1; j <= L; ++j)
         if (mtx_equ[j][i]) {
             for (int k = i + 1; k < K; ++k) mtx_equ[j][k] = (mtx_equ[j][k] != mtx_equ[i][k]);
             vec_res[j] = (vec_res[j] != vec_res[i]);
             mtx_equ[j][i] = 0;
         }
    }
    for (int i = K - 1; i > 0; --i) {
        int tmp = 0;
        for (int j = i + 1; j < K; ++j) tmp += mtx_equ[i][j] * vec_A[j];
        vec_A[i] = (tmp & 1) != vec_res[i];
    }
    
    // Second Step
    char str[MAX_SIZE];
    int vec_tmp[MAX_SIZE];
    
    scanf("%s", str);
    for (int i = 0; i < N; ++i) vec_ans[i + 1] = str[i] - '0';
    
    for (int i = M; i > 0; --i) {
        if (!D[i]) continue;
        matrix_multiply(D[i]);
        for (int j = 1; j <= K; ++j) vec_tmp[j] = 0;
        for (int j = 1; j <= K; ++j)
         for (int k = 1; k <= K; ++k) {
             vec_tmp[j] += vec_ans[S[i] + k - 1] * mtx_ans[k][j];
             vec_tmp[j] &= 1;
         }
        for (int j = 1; j <= K; ++ j) vec_ans[S[i] + j - 1] = vec_tmp[j];
    }
    for (int i = 1; i <= N; ++i) printf("%d", vec_ans[i]); 
    printf("\n");
    
    return 0;
}
