#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 1010;

struct node {
    int len;
    char p[MAXN];
    node *prev, *succ;
    node() {len = 0; p[0] = '\0'; prev = succ = 0;}
};


int main() {
    char p;
    node *Q = new node;
    node *R;
    int i = 0;
    while (true) {
        scanf("%c", &p);
        bool flag = false;
        switch (p) {
            case 'L' :
                if (i > 0) --i;
                break;
                 
            case 'R' :
                ++i;
                break;
             
            case 'U' :
                if (Q->prev) Q = Q->prev;
                break;
                 
            case 'D' :
                if (Q->succ) Q = Q->succ;
                break;
                 
            case 'N' : 
                R = new node;
                if (i < Q->len) {
                    int j = 0;
                    while (i + j < Q->len) {
                        R->p[j] = Q->p[i + j];
                        ++j;
                    }
                    R->len = j;
                    R->p[j] = '\0';
                    Q->len = i;
                    Q->p[i] = '\0';
                }
                i = 0;
                if (Q->succ) {
                    Q->succ->prev = R;
                    R->succ = Q->succ;
                }
                Q->succ = R;
                R->prev = Q;
                Q = R;
                break;
                
            case 'E' :
                i = Q->len;
                break;
                 
            case 'H' :
                i = 0;
                break;
             
            case 'X' : 
                if (i < Q->len) {
                    for (int j = i; j < Q->len; ++j) Q->p[j] = Q->p[j + 1];
                    --(Q->len);
                } else {
                    if (!(Q->succ)) break;
                    for (int j = Q->len; j < i; ++j) Q->p[j] = ' ';
                    Q->len = i;
                    R = Q->succ;
                    for (int j = 0; j <= R->len; ++j) Q->p[Q->len + j] = R->p[j];
                    Q->len += R->len;
                    Q->succ = R->succ;
                    if (R->succ) R->succ->prev = Q;
                    delete R;
                }
                break;
                
            case 'B' : 
                if (i > 0) {
                    if (i <= Q->len) {
                        for (int j = i; j <= Q->len; ++j) Q->p[j - 1] = Q->p[j];
                        --(Q->len);
                    }
                    --i;
                } else {
                    if (!(Q->prev)) break;
                    R = Q->prev;
                    for (int j = 0; j <= Q->len; ++j) R->p[R->len + j] = Q->p[j];
                    i = R->len;
                    R->len += Q->len;
                    R->succ = Q->succ;
                    if (Q->succ) Q->succ->prev = R;
                    delete Q;
                    Q = R;
                }
                break;
                
            case 'Q' : 
                flag = true;
                break;
            
            default  :
                if (i <= Q->len) {
                    for (int j = Q->len; j >= i; --j) Q->p[j + 1] = Q->p[j];
                    Q->p[i] = p;
                    ++(Q->len);
                    ++i;
                } else {
                    for (int j = Q->len; j < i; ++j) Q->p[j] = ' ';
                    Q->p[i] = p;
                    Q->p[i + 1] = '\0';
                    ++i;
                    Q->len = i;
                }
                break;
            
        }
        if (flag) break;
    }
    
    while (Q->prev) Q = Q->prev;
    while (Q) {
        printf("%s", Q->p);
        Q = Q->succ;
        if (Q) printf("\12");
    }
    
    return 0;
}
