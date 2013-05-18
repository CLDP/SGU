#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 16010;

int n;
vector<int> x[MAXN];
bool z[MAXN];
int d[MAXN], f[MAXN];
vector<int> value[MAXN];


int dfs(int a) {
    z[a] = true;
    d[a] = 1;
    int largest = 0;
    for (int i = 0; i < x[a].size(); ++i) 
     if (!z[x[a][i]]) {
         dfs(x[a][i]);
         f[x[a][i]] = a;
         d[a] += d[x[a][i]];
         if (d[x[a][i]] > largest) largest = d[x[a][i]];
     }
    
    if (n - d[a] > largest) largest = n - d[a];
    value[largest].push_back(a);
    return 0;
}



int main() {
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    dfs(a);
    
    int i = 0;
    while (value[i].empty()) ++i;
    sort(value[i].begin(), value[i].end());
    
    cout << i << " " << value[i].size() << endl;
    cout << value[i][0];
    for (int j = 1; j < value[i].size(); ++j) cout << " " << value[i][j];
    cout << endl;
    
    return 0;
}
