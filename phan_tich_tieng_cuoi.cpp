#include <bits/stdc++.h>
#define reu(i,a,b) for (ll i=(a);i<=(b);++i)
using namespace std;
typedef int64_t ll;
const int  base=311;
const int MOD=1e9+7;
struct data
{
    ll ma;
    int sz;
};
data a[1005];
ll Hash[100005];
ll POW[100005];
int n;
int f[100005];
string s;
ll gethash(int x,int y)
{
    return (Hash[y]-Hash[x-1]*POW[y-x+1]+1ll*MOD*MOD)%MOD;
}
void Enter()
{
    freopen("input.txt","r",stdin);
    cin>>n>>s;
    reu(i,1,n)
    {
        string st;
        cin>>st;
        a[i].sz=st.size();
        a[i].ma=0;
        reu(j,0,st.size()-1) a[i].ma=(a[i].ma*base+st[j]-'a'+1)%MOD;
    }
    int nn=s.size();
    s='#'+s;
    POW[0]=1;
    Hash[0]=0;
    reu(i,1,nn) POW[i]=(POW[i-1]*base)%MOD;
    reu(i,1,nn) Hash[i]=(Hash[i-1]*base+s[i]-'a'+1)%MOD;
    f[0]=0;
    reu(i,1,nn)
    {
        reu(j,1,n)
        {
            if (i<a[j].sz) continue;
            if (gethash(i-a[j].sz+1,i)==a[j].ma) f[i]=max(f[i],f[i-a[j].sz]+a[j].sz);
        }
    }
    int ans=0;
    reu(i,1,nn) ans=max(ans,f[i]);
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
