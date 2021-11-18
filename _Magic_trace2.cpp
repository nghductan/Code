#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define ll long long
const int N=3e4;
const ll oo=1e16;
using namespace std;
int a[N],n;
ll f[N][3];
vector<int> ans;
ll Magic(int i,int pre)
{
    if (pre==3) return -oo;
    if (i>n) return 0;
    if (f[i][pre]!=-1) return f[i][pre];
    return f[i][pre]=max(Magic(i+1,pre+1)+a[i],Magic(i+1,0));
}
void trace(int i,int pre)
{
    if (pre==3) return;
    if (i>n) return;
    ll res=f[i][pre];
    if (res==Magic(i+1,pre+1)+a[i])
    {
        ans.push_back(i);
        trace(i+1,pre+1);
        return;
    }
    if (res==Magic(i+1,0))
    {
        trace(i+1,0);
        return;
    }
}
void Enter()
{
    cin>>n;
    reu(i,1,n) cin>>a[i];
    memset(f,-1,sizeof f);
    cout<<Magic(1,0)<<'\n';
    trace(1,0);
    for (auto x:ans) cout<<x<<' ';
}
int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    Enter();
    return 0;
}
