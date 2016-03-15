#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define Maxn 1000005
#define maxn 300
#define inf 0x3fffffff
using namespace std;
int head[1005],k;
struct Edge
{
    int e;
    int w;
    int next;
}edge1[Maxn],edge2[maxn];
void add(Edge *edge,int s,int e,int w)
{
    edge[k].e=e;
    edge[k].w=w;
    edge[k].next=head[s];
    head[s]=k++;
}
void spfa(int s,int n,int *dis,Edge *edge)
{
    int st,ed;
    bool vis[1005];
    queue<int> q;
    memset(vis,false,sizeof(vis));
    q.push(s);
    vis[s]=true;
    for(int i=0;i<=n;i++)
        dis[i]=inf;
    dis[s]=0;
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        vis[st]=false;
        for(int i=head[st];i!=-1;i=edge[i].next)
        {
            ed=edge[i].e;
            if(dis[ed]>dis[st]+edge[i].w)
            {
                dis[ed]=dis[st]+edge[i].w;
                if(!vis[ed])
                {
                    vis[ed]=true;
                    q.push(ed);
                }
            }
        }
    }
}
int ans=inf;
bool visit[15];
void dfs(int p,int now,int sum,int n,Edge *edge)
{
    if(sum>ans)
        return ;
    if(now==n)
    {
        ans=min(ans,sum);
        return ;
    }
    for(int i=head[p];i!=-1;i=edge[i].next)
    {
        int e=edge[i].e;
        int w=edge[i].w;
        if(!visit[e])
        {
            visit[e]=true;
            dfs(e,now+1,sum+w,n,edge);
            visit[e]=false;
        }
    }
}
int main()
{
    int T,n,m,K;
    int point[15],dis[15][1005];
    scanf("%d",&T);
    while(T--)
    {
        K=0;
        memset(dis,0,sizeof(dis));
        memset(head,-1,sizeof(head));
        scanf("%d%d%d",&n,&m,&K);
        while(m--)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(edge1,x,y,w);
            add(edge1,y,x,w);
        }
        for(int i=0;i<K;i++)
        {
            scanf("%d",&point[i]);
            spfa(point[i],n,dis[i],edge1);
        }
        spfa(1,n,dis[K],edge1);
        k=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<K;i++)
        {
            add(edge2,K,i,dis[K][point[i]]);
            add(edge2,i,K,dis[K][point[i]]);
        }
        for(int i=0;i<K;i++)
            for(int j=0;j<K;j++)
            {
                if(i!=j)
                    add(edge2,i,j,dis[i][point[j]]);
            }
        ans=inf;
        memset(visit,false,sizeof(visit));
        visit[K]=true;
        dfs(K,1,0,K+1,edge2);
        printf("%d\n",ans);
    }
    return 0;
}
