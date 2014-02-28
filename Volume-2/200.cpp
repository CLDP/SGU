#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 105;
const long long HP = 1000000000000000;
const int PRIME[100] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
                         31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
                         73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
                         127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
                         179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
                         233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
                         283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 
                         353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
                         419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 
                         467, 479, 487, 491, 499, 503, 509, 521, 523, 541};


bool A[MAXN][MAXN]; // The matrix


int Gauss(int equ, int var) {
    int k;
    
    int col = 0; // current column
    for (k = 0; k < equ && col < var; ++k, ++col) {
        int max_r = k;
        for (int i = k + 1; i < equ; ++i)
         if (A[i][col]) {
             max_r = i;
             break;
         }
        
        if (max_r != k) 
         for (int j = k; j < var + 1; ++j) swap(A[k][j], A[max_r][j]);
         
        if (A[k][col] == 0) {
            --k;
            continue;
        }
        
        for (int i = k + 1; i < equ; ++i) {
            if (A[i][col]) {
                for (int j = col; j < var + 1; ++j) A[i][j] = (A[i][j] != A[k][j]);
            }
        }
    }
    
    return var - k;
}


int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, j = 0;
        cin >> a;
        while (a > 1) {
            if (a % PRIME[j] == 0) {
                A[j][i] = !A[j][i];
                a /= PRIME[j];
            } else {
                ++j;
            }
        }
    }
    
    int free_num = Gauss(N, M);
    long long ansL = 1, ansH = 0;
    for (int i = 0; i < free_num; ++i) {
        ansL = ansL + ansL;
        ansH = ansH + ansH;
        ansH += ansL / HP;
        ansL %= HP;
    }
    
    --ansL;
    
    if (ansH > 0) {
        cout << ansH;
        long long ZERO = HP / 10;
        while (ansL < ZERO) {
            cout << 0;
            ZERO /= 10;
        }
    }
    cout << ansL << endl;
    
    return 0;
}
