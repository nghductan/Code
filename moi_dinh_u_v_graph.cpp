#include <bits/stdc++.h>
const int N=255;
using namespace std;
typedef pair<int,int> pii;
int f[N][N],check[N],n,m,s,t,ans=0;
vector<int> adj[N];
void bfs()
{
    queue<pair<int,int>> q;
    q.push({s,t});
    f[s][t]=0;
    while (q.size())
    {
        pii u=q.front();
        q.pop();
        for (auto v:adj[u.first])
        {
            for (auto _v:adj[u.second])
            {
                if (f[v][_v]!=-1) continue;
                f[v][_v]=f[u.first][u.second]+1;
                q.push({v,_v});
            }
        }
    }

    int res=0x3f3f3f3f;
    for (int i=1;i<=n;i+=1) if (f[i][i]!=-1) res=min(res,f[i][i]);
    cout<<res;
}
void Enter()
{
    //freopen("input.txt.txt","r",stdin);
    //tìm đường đi ngắn nhất của đồ thị vô hướng không trọng số.
    cin>>n>>m;
    cin>>s>>t;
    memset(f,0xff,sizeof f);
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bfs();
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
