#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)

using namespace std;
int f[105][105];
int Magic(int n,int m)
{
    if (n==m) return 1;
    if (f[n][m]!=-1) return f[n][m];
    int res=0x3f3f3f3f;
    for (int i=1;i<=n-1;i+=1)
    {
        res=min(res,Magic(i,m)+Magic(n-i,m));
    }
    for (int i=1;i<=m-1;i+=1) res=min(res,Magic(n,i)+Magic(n,m-i));
    return f[n][m]=res;
}
void Enter()
{
    int n,m;
    memset(f,-1,sizeof f);
    cin>>m>>n;
    cout<<Magic(n,m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Enter();
    return 0;
}
