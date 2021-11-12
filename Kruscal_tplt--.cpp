#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define int long long
using namespace std;
const int N=1e5+7;
struct data
{
    int u,v,w;
};
vector<data> Edge;
int n,m,k,cnt;
int par[N];
void Enter()
{
    cin>>n>>m>>k;
    reu(i,1,m)
    {
        int x,y,z;
        cin>>x>>y>>z;
        Edge.push_back({x,y,z});
    }
}
int findd(int x)
{
    if (par[x]!=x) return par[x]=findd(par[x]);
    return x;
}
bool Unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    if (x==y) return 0;
    if (x>y) swap(x,y);
    cnt--;
    par[y]=x;
    return 1;
}
void Solve()
{
    reu(i,1,n) par[i]=i;
    sort(Edge.begin(),Edge.end(),[&](data a,data b){return a.w<b.w;});
    int ans=0;
    cnt=n;
   // for (auto e:Edge) cout<<e.u<<' '<<e.v<<' '<<e.w<<endl;
    for (auto e:Edge)
    {
        int u=e.u;
        int to_v=e.v;
        int ts=e.w;
        if (k==cnt) cout<<ans,exit(0);
        if (Unionn(u,to_v)) ans+=ts;
    }
}
int32_t main()
{
    freopen("input.txt","r",stdin);
    Enter();
    Solve();
    return 0;
}
