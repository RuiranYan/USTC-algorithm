/*
 * 偏序关系:
 * 平面若干点的最大子集S满足S中任意两点x1<=(>=)x2,y1<=(>=)y2均成立。
 * INPUT:
 * 第一行n，之后是n个二元组。
 * OUTPUT:
 * S大小
 */



# include <iostream>
# include <algorithm>

using namespace std;
typedef struct d {
    int x;
    int y;
} d;

bool cmp(d a, d b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    d a[10000];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x;
        cin >> a[i].y;
    }
    sort(a, a + n, cmp);
//    for (int i = 0; i < n; ++i) {
//        cout<<a[i].x<<" "<<a[i].y<<endl;
//    }
    int dp[10000];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[i].y >= a[j].y && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int max = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > max) max = dp[i];
    }
//    for (int i = 0; i < n; ++i) {
//        cout<<dp[i]<<endl;
//    }
    cout<<max;
    return 0;
}
