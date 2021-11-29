#include <bits/stdc++.h>
#define ll long long
#define reu(i,a,b) for (int i=a;i<=b;++i)

using namespace std;
ll n,a[100005],m;
int tknp(int l,int r,int val)
{
    int vt=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid]<=val) {vt=mid; l=mid+1;} else r=mid-1;
    }
    return vt;
}
void Enter()
{
    cin>>n>>m;
    ll ans=0;
    reu(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    reu(i,1,n-1)
    {
        int vt=tknp(i+1,n,m-a[i]);
        if (vt!=-1) {ans=max(ans,a[i]+a[vt]);}
    }
   cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    Enter();
    return 0;
}
