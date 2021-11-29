#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=2e3+7;

using namespace std;
int f[N],n,t[N],r[N];
int Magic(int i)
{
    if (i>n) return 0;
    if (f[i]!=-1) return f[i];
    int res=0x3f3f3f3f;
    res=min(res,Magic(i+1)+t[i]);
    if (i!=n) res=min(res,Magic(i+2)+r[i]);
    return f[i]=res;
}
void Enter()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    memset(f,-1,sizeof f);
    reu(i,1,n) cin>>t[i];
    reu(i,1,n-1) cin>>r[i];
    cout<<Magic(1);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
