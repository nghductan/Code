#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;i+=1)
const int N=2e5+7;
using namespace std;
int n,a[N];
void Enter()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i+=1) cin>>a[i];
    for (int i=0;i<n;i+=1)
    {
        int res=a[i];
        int cnt=1;
        int j=i+1;
        while (true)
        {
            int _next=lower_bound(a+j,a+n,2*res-a[i])-a;
            if (_next==n) break;
            cnt++;
            res=a[_next];
            j=_next+1;
        }
        ans=max(ans,cnt);
    }
    cout<<n-ans<<'\n';
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        Enter();
    }
    return 0;
}
