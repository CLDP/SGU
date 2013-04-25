#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > x[7];
bool line[110];
int num[110];
vector<pair<int, char> > answer;


int dfs(int a) {
    for (int i = 0; i < x[a].size(); ++i) {
        if (line[abs(x[a][i].second)]) continue;
        line[abs(x[a][i].second)] = true;
        dfs(x[a][i].first);
        if (x[a][i].second > 0) 
            answer.push_back(make_pair(abs(x[a][i].second), '-'));
        else
            answer.push_back(make_pair(abs(x[a][i].second), '+'));
    }
    return 0;
}


int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x[a].push_back(make_pair(b, i + 1));
        x[b].push_back(make_pair(a, - i - 1));
        ++num[a];
        ++num[b];
    }
    
    int ans = 0;
    for (int i = 0; i <= 6; ++i) ans += (num[i] & 1);
    if (ans > 2) {
        // No Eular Path for 3 or more odd points
        cout << "No solution" << endl;
    } else 
    if (ans > 0) {
        for (int i = 0; i <= 6; ++i) 
         if (num[i] & 1) {
             dfs(i);
             break;
         }
    } else {
        for (int i = 0; i <= 6; ++i)
         if (num[i] > 0) {
             dfs(i);
             break;
         }
    }
    
    // The graph is not connected
    for (int i = 1; i <= n; ++i)
     if (!line[i]) {
         cout << "No solution" << endl;
         return 0;
     }
    
    for (int i = 0; i < answer.size(); ++i) 
     cout << answer[i].first << " " << answer[i].second << endl;
    
    return 0;
}
