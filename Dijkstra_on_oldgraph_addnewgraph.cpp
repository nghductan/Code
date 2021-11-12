#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define fi first
#define se second
#define int long long
const int N=1e5+1;
const int oo=1e16;
using namespace std;
vector<pair<int,pair<int,int>>> g[N];
int n,m,p,l,k;
int cost[N][11];
void Enter()
{
    cin>>n>>m>>p>>l>>k;
    while (m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({0,{y,z}});
        g[y].push_back({0,{x,z}});
    }
}
void bfs(int i)
{
    queue<int> q;
    int f[N];
    memset(f,-1,sizeof f);
    f[i]=0;
    q.push(i);
    while (q.size())
    {
        int u=q.front();
        q.pop();
        for (auto e:g[u])
        {
            int v=e.se.fi;
            if (f[v]!=-1) continue;
            f[v]=f[u]+1;
            if (f[v]>l) continue;
            g[i].push_back({1,{v,p}});
           // cout<<i<<' '<<v<<' '<<p<<endl;
            if (f[v]<l) q.push(v);
        }
    }

}
void Dijkstra()
{
    reu(i,1,n)
    reu(j,0,k) cost[i][j]=oo;
    cost[1][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    pq.push({0,{1,0}});
    while (pq.size())
    {
        int u=pq.top().se.fi;
        int w=pq.top().fi;
        int used=pq.top().se.se;
        pq.pop();
        if (cost[u][used]<w) continue;
        for (auto e:g[u])
        {
            int v=e.se.fi;
            int to_v=e.se.se;
            int _used=e.fi;
            if (_used==0)
            {
                if (cost[v][used]>w+to_v) {cost[v][used]=w+to_v;pq.push({cost[v][used],{v,used}});}
            } else
            {
                if (used<k) if (cost[v][used+1]>w+to_v){cost[v][used+1]=w+to_v; pq.push({cost[v][used+1],{v,used+1}});}
            }
        }
    }

    int ans=1e16;
    for (int i=0;i<=k;++i) ans=min(ans,cost[n][i]);
    cout<<ans;
}
void Init()
{
    reu(i,1,n-1) bfs(i);
    Dijkstra();
}
int32_t main()
{
    freopen("input.txt","r",stdin);
    Enter();
    Init();
    return 0;
}
