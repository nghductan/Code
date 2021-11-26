#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define ll long long
const ll oo=0x3f3f3f3f3f3f3f3f;
const int N=2e4;
using namespace std;
ll a[N],n,max_x=0,k;
bool check(ll x)
{
    if (x<max_x) return 0;
    ll tmp=x;
    int cnt=1;
    reu(i,1,n)
    {
        if (tmp>=a[i])
        {
            tmp-=a[i];
        } else
        {
            tmp=x-a[i];
            cnt++;
        }
    }
    if (cnt>k) return 0;
    return 1;
}
void Enter()
{
    cin>>n>>k;
    ll ans;
    ll dau=1,cuoi=oo;
    reu(i,1,n) {cin>>a[i]; max_x=max(max_x,a[i]);}
    while (dau<=cuoi)
    {
        ll mid=(dau+cuoi)/2;
        if (check(mid)) {ans=mid;cuoi=mid-1;} else dau=mid+1;
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
