#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define int long long
#define fi first
#define se second
const int N=1e5+7;
const int oo=1e16;
using namespace std;
int D[64],n,m,k,l;
int cost[N][64];
vector<pair<int,int>> g[N];
void Dijkstra()
{
    int _maskk=pow(2,k)-1;
    reu(i,1,n)
    reu(j,0,_maskk) cost[i][j]=oo;
    cost[1][D[1]]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    pq.push({0,{1,D[1]}});
    while (pq.size())
    {
        int u=pq.top().se.fi;
        int w=pq.top().fi;
        int mask=pq.top().se.se;
        pq.pop();
        if (w>cost[u][mask]) continue;
        for (auto e:g[u])
        {
            int v=e.fi;
            int to_v=e.se;
            if (w+to_v<cost[v][mask|D[v]]) {cost[v][mask|D[v]]=w+to_v;pq.push({cost[v][mask|D[v]],{v,mask|D[v]}});}
        }
    }
    int _mask=pow(2,l);
    if (cost[n][_mask-1]==oo) cout<<-1; else cout<<cost[n][_mask-1];
}
void Enter()
{
    cin>>n>>m>>k>>l;
    reu(i,1,n)
    {
        int sl;
        cin>>sl;
        reu(j,1,sl) {int y; cin>>y; D[i]|=(1<<(y-1));}
    }
    while (m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    Dijkstra();
}
int32_t main()
{
    freopen("input.txt","r",stdin);
    Enter();
    return 0;
}
