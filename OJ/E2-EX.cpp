#include <iostream>
#include <map>
#include <set>
#include<algorithm>
#include <string>

using namespace std;
typedef struct edge {
    int i;
    int j;
    int alpha;
} edge;
edge a[1000000];
bool cmp(edge a, edge b);

int main() {
    int n, m;
    int x, y, alpi;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &alpi);
        a[i].i = x;
        a[i].j = y;
        a[i].alpha = alpi;
    }
    sort(a,a+m,cmp);
    for (int i = 0; i < m; ++i) {
        printf("%d ", a[i].alpha);
    }
}

bool cmp(edge a, edge b) {
    return a.alpha > b.alpha;
}

