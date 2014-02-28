#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 11000;
const int INF = 1000000000;

map<string, string> mp;

int stoi(const string &s){
    int sign = 1, i = 0, ans = 0;
    if (s[0] == '-') sign = -1, ++i;
    for(; i < s.size(); ++i) ans = ans * 10 + s[i] - '0';
    return ans * sign;
}

string clean(const string &s) {
    int L = 0, R = s.size();
    while (s[L] == ' ' || s[L] == ';') ++L;
    while (R > 0 && s[R - 1] == ' ' || s[R - 1] == ';') --R;
    return s.substr(L, R - L);
}

string Super(string s, int &x, int &y){
    int L = 0;
    while (s[L] != '(') ++L; ++L;
    while (s[L] == ' ') ++L; s = s.substr(L, s.size() - L);
    L = 0;
    while (s[L] != ',') ++L;
    string str = clean(s.substr(0, L));

    while (s[L] == ' ' || s[L] == ',') ++L;
    s = s.substr(L, s.size() - L);
    for (L = 0; L < s.size(); ++L)
     if (s[L] == ',' || s[L] == ')') break;
    x = stoi(clean(s.substr(0, L)));
    if (x < 0) x = (mp[str]).size() + x;
    if (s[L] == ')') return str;
   
    while (s[L] == ' ' || s[L] == ',') ++L;
    s = s.substr(L, s.size() - L);
    for (L = 0; L < s.size(); ++L)
     if(s[L] == ')') break;
    y = stoi(clean(s.substr(0, L)));
    if (y < 0) y = (mp[str]).size() - x + y;
    return str;
}

string get_string(const string &s){
    if (s[0] == '$') {
        return mp[s];
    } else {
        int x, y = INF;
        string str = mp[Super(s, x, y)];
        return str.substr(x, y);
    }
}

char trash[MAXN], s[MAXN], s2[MAXN];

int main() {
    int n, m;
    scanf("%d%d\n", &n, &m);
    while (n--) {
        scanf("%[^=]s", s); string str = s;     str = clean(str);
        scanf("%c", trash);
        string str2;        getline(cin, str2); str2 = clean(str2);
        mp[str] = str2.substr(1, str2.size()-2);
    }
    while (m--) {
        char MODE = ' ';
        while (MODE == ' ') scanf("%c", &MODE);
        if (MODE == '$') {
            scanf("%[^=]s", s); string str = "$";   str = clean(str + s);
            scanf("%c", trash);
            string str2;        getline(cin, str2); str2 = clean(str2);
            mp[str] = get_string(str2);
        }
        if (MODE == 's') {
            scanf("%[^=]s", s2); string str = "s";   str = clean(str + s2);
            scanf("%c", trash);
            string str2;         getline(cin, str2); str2 = clean(str2);
            int a, b = MAXN;
            string fir = Super(str, a, b), sec = get_string(str2);
            string S = mp[fir]; S.replace(a, b, sec); mp[fir] = S;
        }
        if (MODE == 'p') {
            scanf("%[^(]s", trash); scanf("%c", trash);
            string str;   getline(cin, str);
            int L = str.size(), cnt = 0;
            while (L > 0 && !cnt) {
                if (str[L - 1] == ')') ++cnt;
                --L;
            }
            str = clean(str.substr(0, L));
            cout << get_string(str) << endl;
        }
    }
}
