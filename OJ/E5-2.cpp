/*
 * 最短路径:
 * INPUT:
 * N M S T //节点个数，边个数，源点，目标节点
 * U_i V_i W_i //单向边(可能有重边)
 * //N<=10^5, M <=10^6
 * OUTPUT:
 * 如果有最短路径输出最短距离，否则输出-1
 */



#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define maxnum 100000
#define INF 10000000

using namespace std;

typedef char VertexType;
//边
typedef struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;
//顶点
typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[maxnum];

typedef struct {
    AdjList vertices;//数组
    int vexnum, arcnum;
} ALGraph;

//顶点节点，保存id和到源顶点的估算距离，优先队列需要的类型
struct Node {
    int id;//源顶点id
    int w;//估算距离

    //因要实现最小堆，按升序排列，因而需要重载运算符，重定义优先级，以小为先
    friend bool operator<(struct Node a, struct Node b) {
        return a.w > b.w;
    }
};

int path[maxnum];
int visited[maxnum] = {0};
Node dist[maxnum];
priority_queue<Node> q;

void Dijkstra(ALGraph g, int v0, int t, int n) {
    //初始化

    for (int i = 1; i <= n; i++) {
        dist[i].id = i;
        dist[i].w = INF;
        path[i] = -1;       //每个顶点都无父亲节点
        visited[i] = 0;     //都未找到最短路
    }
    dist[v0].w = 0;
    q.push(dist[v0]);
    while (!q.empty()) {
        Node cd = q.top();
        q.pop();
        int u = cd.id;

        if (visited[u])
            continue;
        visited[u] = 1;
        if (u == t) break;
        ArcNode *p = g.vertices[u].firstarc;

        while (p) {
            int tempv = p->adjvex;
            int tempw = p->weight;

            if (!visited[tempv] && dist[tempv].w > dist[u].w + tempw) {
                dist[tempv].w = dist[u].w + tempw;
                path[tempv] = u;
                q.push(dist[tempv]);
            }
            p = p->nextarc;
        }
    }
}

void CreateALGraph(ALGraph &g, int arc, int vex) {
    g.arcnum = arc;
    g.vexnum = vex;
    int v1, v2, i, w;

    for (i = 1; i <= vex; i++) {
        g.vertices[i].firstarc = NULL;
    }
    for (i = 1; i <= arc; i++) {
        cin >> v1 >> v2 >> w;
        ArcNode *q = (ArcNode *) malloc(sizeof(ArcNode));
        q->adjvex = v2;
        q->weight = w;

        q->nextarc = g.vertices[v1].firstarc;
        g.vertices[v1].firstarc = q;
    }
}

int DFS(ALGraph g, int i, int j) {
    visited[i] = 1;
    ArcNode *p = g.vertices[i].firstarc;
    while (p) {
        if (p->adjvex == j)
            return 1;
        //cout <<(visited[p->adjvex])<< endl;
        if (!(visited[p->adjvex]) && DFS(g, p->adjvex, j))
            return 1;
        p = p->nextarc;
    }
    return 0;
}

int BFS(ALGraph g, int i, int j) {
    queue<int> q;//
    q.push(i);
    visited[i] = 1;
    ArcNode *p;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        p = g.vertices[temp].firstarc;

        while (p) {
            //cout << p->adjvex;
            if (p->adjvex == j)
                return 1;
            if (!(visited[p->adjvex])) {
                visited[p->adjvex] = 1;
                q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
    return 0;//返回不可少
}

int main() {
    int N, M, start, e;
    scanf("%d%d%d%d", &N, &M, &start, &e);
    int a, b, c;
    map<pair<int, int>, int> mp;
    map<pair<int, int>, int>::iterator it;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        pair<int, int> pa(a, b);
        it = mp.find(pa);
        if (it != mp.end()) {
            if (c < mp[pa]) mp[pa] = c;
        } else {
            mp[pa] = c;
        }
    }
    ALGraph g;
    g.arcnum = M;
    g.vexnum = N;

    int v1, v2, i, w;

    for (i = 1; i <= N; i++) {
        g.vertices[i].firstarc = NULL;
    }
    for (it = mp.begin(); it != mp.end(); ++it) {
        v1 = it->first.first;
        v2 = it->first.second;
        w = it->second;
        ArcNode *q = (ArcNode *) malloc(sizeof(ArcNode));
        q->adjvex = v2;
        q->weight = w;

        q->nextarc = g.vertices[v1].firstarc;
        g.vertices[v1].firstarc = q;

    }
    Dijkstra(g, start, e, N);

    if (dist[e].w != INF)
        cout << dist[e].w << endl;
    else
        cout << -1 << endl;
}
