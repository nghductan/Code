#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define ll long long
const ll oo=1e16;
using namespace std;
void Enter()
{
    int n;
    ll f[60][60];
    int trace[60][60];
    cin>>n;
    reu(i,1,n)
    reu(j,1,n)
    {
        ll c;
        cin>>c;
        if (i==j) {f[i][j]==0;continue;}
        if (c==0) f[i][j]=oo; else f[i][j]=f[j][i]=c;
    }
    int p,q;
    cin>>p>>q;
    reu(i,1,n)
    reu(j,1,n) trace[i][j]=j;
    reu(k,1,n)
    reu(i,1,n)
    reu(j,1,n)
    {
        if (i==j) continue;
        if (f[i][j]>f[i][k]+f[k][j]) {f[i][j]=f[i][k]+f[k][j]; trace[i][j]=trace[i][k]; }
    }
   // trace[p]=p;
   //trace[u][v] là đỉnh kề với u trong đường đi ngắn nhất từ u đến v
   // nếu có dường đi trức tiếp từ u->v trace[u][v]=v;
    if (f[p][q]==oo) cout<<-1,exit(0); else cout<<f[p][q]<<endl;
    vector<int> res;
    do
    {
        res.push_back(p);
        p=trace[p][q];
    } while (res.back()!=q);
    for (auto const &x:res) cout<<x<<' ';
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    Enter();
    return 0;
}
