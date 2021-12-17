/*
 * 最大流:
 * INPUT:
 * N M S T //节点个数，边个数，源点，目标节点
 * U_i V_i C_i //单向边(可能有重边)
 * //N<=500, M<=20000
 */


#include<bits/stdc++.h>
#include<string.h>
using namespace std;
const int maxn=600;     ///最大点个数
const int inf=0x7fffffff;
int mp[maxn][maxn],n;
int p[maxn] ;
bool vis[maxn];
///mp：邻接矩阵
///p：点的前驱
///vis：找增广路时用于避免增广点的重复选取
bool EK_Bfs(int st,int ed) {
    queue<int>que;
    for(int i=0;i<=n;i++) p[i]=-1,vis[i]=false;  ///初始化
    que.push(st);
    vis[st]=true;
    while(!que.empty()) {
        int e=que.front();
        if(e==ed) return true;  ///到达ed点，说明增广路已经找到
        que.pop();
        for(int i=1;i<=n;i++) {
            if(mp[e][i]>0&&!vis[i]) {    ///如果当前边有流且增广点未标记
                vis[i]=true;
                p[i]=e;        ///记录增广点前驱点
                que.push(i);

            }
        }
    }
    return false;       ///找不到增广路
}
int EK_Max_Flow(int st,int ed) {
    int max_flow=0;     ///最大流量
    while(EK_Bfs(st,ed)) {  ///只要能找到从st到ed的增广路，就继续循环
        int minn=inf;
        int u=ed;
        while(p[u]!=-1) {       ///找出增广路中的“瓶颈”边
            minn=min(mp[p[u]][u],minn);
            u=p[u];
        }
        max_flow+=minn;     ///累加进最大流
        u=ed;
        while(p[u]!=-1) {   ///修改路径上的边容量
            mp[p[u]][u]-=minn;
            mp[u][p[u]]+=minn;
            u=p[u];
        }
    }
    return max_flow;
}
int main()
{
    int m,st,ed;      ///m:边数目  st:起点  ed:终点
    cin>>n>>m;
    cin>>st>>ed;
    memset(mp, 0, sizeof(mp));
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        if(u==v) continue;
        mp[u][v]+=w;     ///建立u到v的权值为w的边
    }
    cout<<EK_Max_Flow(st,ed)<<endl;
    return 0;
}

