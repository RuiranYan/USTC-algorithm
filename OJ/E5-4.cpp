/*
 * 最大半连通子图:
 * 在有向图G中，找出节点数最多的一个节点集合S，使得S中的任意两个节点A,B满足“A可达B”或者“B可达A”。
 * INPUT:
 * N M
 * U_i V_i
 * //N<=5000, M<=10^5
 *
 * 解答参考:https://blog.csdn.net/qq_45961321/article/details/105936336
 */

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;
const int N = 1e5 + 10, M = 2e6 + 10;
typedef long long LL;
//h[]原图的表头  hs[]缩点后得到的这张DAG图的表头
int h[N], hs[N], e[M], ne[M], idx;
//表示节点u深度优先遍历的序号（也就是节点u被访问的时间点）
//表示节点u或节点u的子孙能够通过非父子边追溯到的dfn最小的节点序号
//即回到最早的过去（也就是节点u通过有向边可回溯到的最早的时间点）
//num表示时间戳
int dfn[N], low[N], num;
//a=id[x]表示x这个节点属于a这个强连通分量
//cnt[i]=100表示i这个强连通分量有100个节点
//scc表示强连通分量的编号 scc=3表示第3个强连通分量 最终也只有scc个强连通分量
int id[N], cnt[N], scc;
//栈用来存储访问的节点  top是栈顶指针
int stk[N], top;
//din存储每个节点的入度 dout存储每个节点的出度
int din[N], dout[N];
//in_stk[i]=true表示节点i还在栈中
bool in_stk[N];
//f[i]表示以第 i 个点为终点的最长链节点数量之和
//g[i]表示让f[i]取到最大值时对应的方案数
LL f[N], g[N];
int n, m;

void add(int h[], int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++num;    //给节点u分配一个时间戳
    stk[++top] = u;           //将节点u入栈
    in_stk[u] = true;         //标记节点u在栈中
    //遍历节点u的所有邻接点
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i]; //u的邻接点j
        //根据分析得出：先会执行else if中的更新语句,才会执行if中的回溯过程中的更新语句
        //如果节点j还没有被访问过
        if (!dfn[j]) {
            tarjan(j);//递归访问j
            //回溯是更新从节点j往回到节点u这条路径上的所有节点的low值
            low[u] = min(low[u], low[j]);
        }
            //否则说明节点j已经被访问过了 看j是否还在栈中
            //如果还在栈中 那么就说明形成了环 即存在强连通分量
            //当走到这里时说明j先于u被访问,因此u可以追溯到更早的过去
            //于是用更早的dfn[j]来更新low[u]
        else if (in_stk[j])
            low[u] = min(low[u], dfn[j]);
    }
    //退无可退 即此时u不能追溯到更早的过去了 那么它就是这个强连通分量的入口
    if (dfn[u] == low[u]) {
        scc++;  //强连通分量的个数+1
        int y;
        //输出这个强连通分量中所包含的节点
        do {
            y = stk[top--];       //强连通分量的节点y
            in_stk[y] = false;    //标记节点y不在栈中
            id[y] = scc;      //节点y属于scc这个强连通分量
            cnt[scc]++;     //scc这个强连通分量中的节点个数增加了y这个节点
        } while (y != u);
    }
}

int main() {
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    scanf("%d%d", &n, &m);
    //建立原图
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(h, a, b);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    unordered_set<LL> S; //哈希表  对边判重 消除重边
    for (int i = 1; i <= n; i++) {
        //遍历节点i的所有邻接点
        for (int j = h[i]; ~j; j = ne[j]) {
            int k = e[j]; //i的邻接点k
            int a = id[i];    //节点i所在的强连通分量 也就是缩点后得到的某个节点a
            int b = id[k];    //节点k所在的强连通分量 也就是缩点后得到的某个节点b
            //节点a,b之间这条边的编号哈希成>1000000的一个整数值
            LL hash = a * 1000000ll + b;
            //如果a和b都不在同一个强连通分量中并且这条边还没有出现过
            if (a != b && !S.count(hash)) {
                //将缩点后的这张DAG图真的建立出来
                add(hs, a, b);
                S.insert(hash);
            }
        }
    }

    //tarjan求完后，scc的编号递减顺序就是拓扑序列
    //预处理出f[]和g[]
    for (int i = scc; i > 0; i--) {
        if (!f[i])   //如果当前点没有更新，就进行初始化
        {
            f[i] = cnt[i];
            g[i] = 1;
        }
        //遍历节点i的所有邻接点
        for (int j = hs[i]; ~j; j = ne[j]) {
            int k = e[j]; //i的邻接点k
            //通过i能够更新k  只是让f[k]变多了 并没有产生新的方案
            if (f[k] < f[i] + cnt[k]) {
                f[k] = f[i] + cnt[k];
                g[k] = g[i];
            }
                //比如f[k]=8  f[i]=5 cnt[k]=3 那么{8}和{5,3}就是两种不同的方案
                //使得节点k的f值都是8  于是如果相同的话就会产生新方案
            else if (f[k] == f[i] + cnt[k])
                g[k] = (g[k] + g[i]);
        }
    }

    //maxf是记录最大的f[]  sum是记录最大的g[]
    int maxf = 0, sum = 0;
    for (int i = 1; i <= scc; i++) {
        if (f[i] > maxf) {
            maxf = f[i];
            sum = g[i];
        } else if (f[i] == maxf)
            sum = (sum + g[i]);
    }
    printf("%d\n", maxf);
    return 0;
}

