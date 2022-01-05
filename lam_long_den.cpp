#include <bits/stdc++.h>
#define reu(i,a,b) for ( ll i=(a);i<=(b);++i)

using namespace std;
typedef int64_t ll;
int a[52],n,l;
int f[52][52];
bool vis[52][52];
int magic(int l,int r)
{
    if (l==r-1 ) return 0;
    if (vis[l][r]) return f[l][r];
    int ans=0x3f3f3f3f;
    reu(z,l+1,r-1) ans=min(ans,magic(l,z)+magic(z,r)+a[r]-a[l]);
    vis[l][r]=1;
    return f[l][r]=ans;
}

void Enter()
{
    cin>>l>>n;
    reu(i,1,n) cin>>a[i];
    a[n+1]=l;
    cout<<magic(0,n+1);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
