#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=5005;
using namespace std;
int v[N],f[N],_v[N],n,k;
map<int,int> a;
void Enter()
{
   // freopen("input.txt","r",stdin);
    cin>>n>>k;
    reu(i,1,n) cin>>v[i];
    reu(i,1,n) _v[i]=v[i];
}
void Proc()
{
    sort(v+1,v+1+n);
    int cnt=n/k;
    for (int i=n;i>=1;i-=k)
    {
        int _k=k,j=i;
        while (_k--)
        {
            a[v[j--]]=cnt;
        }
        cnt--;
    }
    int res=1;
    reu(i,1,n)
    {
        reu(j,0,i-1) if (a[_v[i]]>=a[_v[j]]) f[i]=max(f[i],f[j]+1);
        res=max(res,f[i]);
    }
    cout<<n-res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    Proc();
    return 0;
}
