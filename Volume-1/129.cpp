#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const double EPISLON = 0.0000001;
const int INF = 1000000;
const int MAXN = 410;
const int MAXM = 1010;


struct point {
    double x,y;
};

struct segment {
    point a, b;
};


int n,m;
point c;
point p[MAXN];
segment seg[MAXM], edge[MAXM];


void swap(point &a, point &b) {
    point t = a;
    a = b;
    b = t;
}

double cross(point a, point b, point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

double calculate_distance(point a, point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool check_intersect(segment s1, segment s2) {
    return max(s1.a.x, s1.b.x) >= min(s2.a.x, s2.b.x)
        && max(s2.a.x, s2.b.x) >= min(s1.a.x, s1.b.x)
        && max(s1.a.y, s1.b.y) >= min(s2.a.y, s2.b.y)
        && max(s2.a.y, s2.b.y) >= min(s1.a.y, s1.b.y)
        && cross(s1.a, s2.b, s2.a) * cross(s2.b, s1.b, s2.a) >= 0
        && cross(s2.a, s1.b, s1.a) * cross(s1.b, s2.b, s1.a) >= 0;
}

bool check_same_point(point a, point b) {
    return abs(a.x - b.x) < EPISLON && abs(a.y - b.y) < EPISLON;
}

bool check_cross(segment s1, segment s2) {
    return check_intersect(s1, s2) && !check_same_point(s1.a, s2.a) &&! check_same_point(s1.b, s2.a) 
        && !check_same_point(s1.a, s2.b) && !check_same_point(s1.b, s2.b);
}

point calccross(point a, point b, point c, point d, bool &flag) {
    double delta = (b.x - a.x) * (c.y - d.y) - (d.x - c.x) * (a.y - b.y);
    point ans;
    if (abs(delta) < EPISLON) {
        flag = false;
        return ans;
    }
    
    ans.x = ((c.y * d.x - c.x * d.y) * (b.x - a.x) - (a.y * b.x - a.x * b.y) * (d.x - c.x)) / delta;
    ans.y = ((a.y * b.x - a.x * b.y) * (c.y - d.y) - (c.y * d.x - c.x * d.y) * (a.y - b.y)) / delta;
    return ans;
}

bool boundary(point now, segment s) {
    double x1 = s.a.x, x2 = s.b.x, y1 = s.a.y, y2 = s.b.y;
    double x = now.x, y = now.y;
    return (abs((y1 - y) * (x2 - x) - (y2 - y) * (x1 - x)) < EPISLON) &&
           (((y1 - y) * (y2 - y) <= 0 && (x1 - x) * (x2 - x) <= 0));
}

int check_inside(point now) {
    int ans = 0;
    segment tmp;
    tmp.a = now;
    tmp.b.x = 5234137;
    tmp.b.y = 6345237;
    for (int i = 1; i <= n; ++i) {
        if (boundary(now, edge[i])) return 0;
        if (check_intersect(tmp, edge[i])) ++ans;
    }
    if (ans & 1) return -1;
    return 1;
}

int cal(segment current) {
    segment now = current;
    int ina = check_inside(now.a), inb = check_inside(now.b), cross_num = 0, tmp_cross_num = 0;
    point cross[10], tmpcross[10];
    if (ina > inb) {
        swap(ina, inb);
        swap(now.a, now.b);
    }
    
    for (int i = 1; i <= n; ++i)
     if (check_intersect(edge[i],now)) {
         bool flag = true;
         point tmp = calccross(edge[i].a, edge[i].b, now.a, now.b, flag);
         if (flag) tmpcross[++tmp_cross_num] = tmp;
     }
    
    for(int i = 1; i <= tmp_cross_num; ++i) {
        bool flag = true;
        for (int j = i+1; j <= tmp_cross_num; ++j)
         if (check_same_point(tmpcross[i], tmpcross[j])) {
             flag = false;
             break;
         }
         
        if (flag) cross[++cross_num] = tmpcross[i];
    }
    
    if (cross_num == 0) {
        if (ina == -1 && inb == -1)
            printf("%.2lf\n", calculate_distance(now.a, now.b));
        else
            printf("0.00\n");
            
    } else 
    if (cross_num == 1) {
        if (ina == -1 && inb == 1 || ina == -1 && inb == 0)
            printf("%.2lf\n", calculate_distance(now.a, cross[cross_num]));
        else
            printf("0.00\n");
            
    } else 
    if (cross_num == 2) {
        int ta[2] = {0}, a = 0, tb[2] = {0}, b = 0;
        for (int i = 1; i <= n; ++i) {
            if (boundary(cross[1], edge[i])) ta[a++] = i;
            if (boundary(cross[2], edge[i])) tb[b++] = i;
        }
        for (int i = 0; i < a; ++i) 
         for (int j = 0; j < b; ++j)
          if (ta[i] == tb[j]) {
              printf("0.00\n");
              return 0;
          }
          
        printf("%.2lf\n", calculate_distance(cross[1], cross[2]));
        
    } else {
        printf("0.00\n");
    }
    
    return 0;
}


int main() {
    int tmp = 0;
    c.y = INF, c.x = -INF;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        if (p[i].y < c.y || p[i].y == c.y && p[i].x > c.x) {
            c.x = p[i].x;
            c.y = p[i].y;
            tmp = i;
        }
    }
    
    swap(p[tmp], p[1]);
    
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> seg[i].a.x >> seg[i].a.y >> seg[i].b.x >> seg[i].b.y;
    
    for (int i = 1; i <= n; ++i)
     for (int j = i+1; j <= n; ++j)
      if (cross(p[i], p[j], c) < 0) swap(p[i],p[j]);
      
    for (int i = 1; i <= n; ++i) {
        edge[i].a = p[i];
        edge[i].b = p[i % n + 1];
    }
    
    for (int i = 1; i <= m; ++i) cal(seg[i]);
    
    return 0;
}
