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
edge e[1000000];
int s[100000];// 记录边所属子树的index
set<int> edgeset[1000000];// 记录子树
int f[100000];//0:该点还未放入;1:放入A；2:放入B

bool cmp(edge a, edge b);

int main() {
    int n, m;
    int x, y, alpi;
    int t;
    int minset, maxset;
    int i;
    set<int>::iterator itr;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &alpi);
        e[i].i = x;
        e[i].j = y;
        e[i].alpha = alpi;
    }
    sort(e, e + m, cmp);
//    for (int i = 0; i < m; ++i) {
//        printf("%d ", e[i].alpha);
//    }
    int k = 0;
    for (i = 0; i < m; ++i) {
        if (f[e[i].i] == 0 && f[e[i].j] == 0) {
            if (e[i].i == e[i].j) {
                // 判断自环
                printf("%d", e[i].alpha);
                break;
            }
            f[e[i].i] = 1;
            f[e[i].j] = 2;
            edgeset[k].insert(e[i].i);
            edgeset[k].insert(e[i].j);
            s[e[i].i] = k;
            s[e[i].j] = k;
            k++;
        } else if (f[e[i].i] != 0 && f[e[i].j] == 0) {
            f[e[i].i] == 1 ? f[e[i].j] = 2 : f[e[i].j] = 1;
            t = s[e[i].i];
            edgeset[t].insert((e[i].j));
            s[e[i].j] = t;
        } else if (f[e[i].j] != 0 && f[e[i].i] == 0) {
            f[e[i].j] == 1 ? f[e[i].i] = 2 : f[e[i].i] = 1;
            t = s[e[i].j];
            edgeset[t].insert((e[i].i));
            s[e[i].i] = t;
        } else {
            if (f[e[i].i] != f[e[i].j]) {
                // 不成奇环时直接将两颗子树相连并将两颗树的序号统一
                minset = (edgeset[s[e[i].i]].size() <= edgeset[s[e[i].j]].size() ? s[e[i].i] : s[e[i].j]);
                maxset = (edgeset[s[e[i].i]].size() <= edgeset[s[e[i].j]].size() ? s[e[i].j] : s[e[i].i]);
                for (itr = edgeset[minset].begin(); itr != edgeset[minset].end(); itr++) {
                    s[*itr] = maxset;
                    edgeset[maxset].insert(*itr);
                }
            } else {
                // 出现矛盾仓库时看是否在同一子树，若在则该边危险系数即为所求，若不在则将子树合并
                if (s[e[i].i] == s[e[i].j]) {
                    printf("%d", e[i].alpha);
                    break;
                } else {
                    minset = (edgeset[s[e[i].i]].size() <= edgeset[s[e[i].j]].size() ? s[e[i].i] : s[e[i].j]);
                    maxset = (edgeset[s[e[i].i]].size() <= edgeset[s[e[i].j]].size() ? s[e[i].j] : s[e[i].i]);
                    for (itr = edgeset[minset].begin(); itr != edgeset[minset].end(); itr++) {
                        s[*itr] = maxset;
                        edgeset[maxset].insert(*itr);
                        f[*itr] == 1 ? f[*itr] = 2 : f[*itr] = 1;
                    }
                }
            }
        }
    }
    if (i == m) printf("0");
}

bool cmp(edge a, edge b) {
    return a.alpha > b.alpha;
}

