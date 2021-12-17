/*
 * 最小生成树:
 * INPUT:
 * N M
 * U_i V_i W_i
 * //M>=N-1, 1<=U_i<=N, 1<=V_i<=N, 1<=W_i<=100
 * //N<=10^5 M<=10^6
 * OUTPUT:
 * 最小生成树总值
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int inf=999999;
int fa[110000];
int n,m;
struct node
{
    int u,v,w;

}q[110000];
void make_set()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
}
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];

}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int kru()
{  int ans=0,cnt=0;
    make_set();
    sort(q+1,q+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int fx=Find(q[i].u);
        int fy=Find(q[i].v);
        if(fx!=fy)
        {

            fa[fx]=fy;
            ans+=q[i].w;
            cnt++;
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);

        }

        printf("%d\n",kru());
    }
    return 0;
}


