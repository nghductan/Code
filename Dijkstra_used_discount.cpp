#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define int long long
#define fi first
#define se second
const int oo=1e16;
const int N=1e5+1;
using namespace std;
int n,m,k,s,t;
int cost[N][6],ans=oo;
vector<pair<int,int>> g[N];
void Dijkstra();
void Enter()
{
    cin>>n>>m>>k>>s>>t;
    while (m--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    Dijkstra();
}
void Dijkstra()
{
    reu(i,1,n)
    reu(j,0,k) cost[i][j]=oo;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    pq.push({0,{s,0}});
    cost[s][0]=0;
    while (pq.size())
    {
        int u=pq.top().se.fi;
        int w=pq.top().fi;
        int used=pq.top().se.se;
        pq.pop();
        if (w>cost[u][used]) continue;
        for (auto e:g[u])
        {
            int to_v=e.se;
            int v=e.fi;
            if (w+to_v<cost[v][used]) {cost[v][used]=w+to_v; pq.push({cost[v][used],{v,used}});}
            if (used<k)
            {
                if (w<cost[v][used+1]) {cost[v][used+1]=w;pq.push({cost[v][used+1],{v,used+1}});}
            }
        }
    }
    for (int i=0;i<=k;++i) ans=min(ans,cost[t][i]);
    cout<<ans;
}
int32_t main()
{
    freopen("input.txt","r",stdin);
    Enter();
    return 0;
}
