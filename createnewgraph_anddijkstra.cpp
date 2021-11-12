#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;
const int oo=1e9+3;
const int N=1e5+1;
int n,k,c[N],D[N],f[N];
vector<pair<int,int>> g[N];
vector<int> adj[N];
void Enter()
{
    cin>>n>>k;
    reu(i,1,n) cin>>c[i]>>D[i];
    while (k--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void bfs(int i)
{
    queue<int> q;
    q.push(i);
    memset(f,-1,sizeof f);
    f[i]=0;
    while (q.size())
    {
        int u=q.front();
        q.pop();
        for (auto v:adj[u])
        {
            if (f[v]!=-1) continue;
            f[v]=f[u]+1;
            if (f[v]>D[i]) continue;
            g[i].push_back({v,c[i]});
            if (f[v]<D[i]) q.push(v);
        }
    }

}
void Dijkstra();
void Init()
{
   reu(i,1,n-1) bfs(i);
    Dijkstra();
}
void Dijkstra()
{
    int cost[N];
    reu(i,1,n) cost[i]=oo;
    cost[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,1});
    while (pq.size())
    {
        int u=pq.top().se;
        int w=pq.top().fi;
        pq.pop();
        if (w!=cost[u]) continue;
        for (auto e:g[u])
        {
            int v=e.fi;
            int to_v=e.se;
            if (cost[v]>w+to_v)
            {
                cost[v]=w+to_v;
                pq.push({cost[v],v});
            }
        }
    }
    cout<<cost[n];
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Enter();
    Init();
    return 0;
}
