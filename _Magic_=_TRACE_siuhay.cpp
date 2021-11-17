#include <bits/stdc++.h>
#define ll long long
const ll oo=1e16;
const int N=1e3+7;
using namespace std;
template<typename T1,typename T2> T1 Maxi(T1 &a, T2 b) {if (a>=b) return a; return b;}
ll f[N][3][3],n,a[N];
vector<int> ans;
ll Magic(int i,int pre,int next)
{
    if (pre==3) return -oo;
    if (next==3) return -oo;
    if (i>n) return 0;
    if (f[i][pre][next]!=-1) return f[i][pre][next];
    return f[i][pre][next]=max(a[i]+Magic(i+1,pre+1,0),Magic(i+1,0,next+1));
}
void trace(int i,int pre,int next)
{
    if (pre==3) return;
    if (next==3) return ;
    if (i>n) return;
    ll res=Magic(i,pre,next);
    if (res==a[i]+Magic(i+1,pre+1,0))
    {
        ans.push_back(i);
        trace(i+1,pre+1,0);
        return;
    }
    trace(i+1,0,next+1);
    return;
}
void Enter()
{
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    memset(f,-1,sizeof f);
    cout<<Magic(1,0,0)<<' ';
    trace(1,0,0);
    cout<<ans.size()<<'\n';
    for (auto const &x:ans) cout<<x<<'\n';

}
int main()
{
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Enter();
    return 0;
}
