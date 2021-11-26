#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define reud(i,a,b) for (int i=a;i>=b;--i)
#define ll long long
const ll oo=0x3f3f3f3f3f3f3f3f;
const int N=1e5+7;
using namespace std;
ll L[N],a[N],f[N],n,k,R[N];
void Enter()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>k;
    reu(i,1,n) cin>>a[i];
    reu(i,1,n) f[i]=f[i-1]+a[i];
   // reu(i,0,n) cout<<f[i]<<' ';
   // exit(0);
    L[0]=-oo;
    R[n+1]=-oo;
    ll ans=oo;
    reu(i,1,n)
    {
        if (i<k) L[i]=-oo; else
        {
            L[i]=max(L[i-1],f[i]-f[i-k]);
        }
    }

    reud(i,n,1)
    {
        if (n-i+1<k) R[i]=-oo; else
        {
            R[i]=max(R[i+1],f[i+k-1]-f[i-1]);
        }
    }
   // int vt;
    reu(i,1,n-k+1) ans=min(ans,max(L[i-1],R[i+k]));
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
