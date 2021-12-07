#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=5005;
using namespace std;
int v[N],f[N],_v[N],n,k,b[N],c[N];
unordered_map<int,int> a;
void Enter()
{
    freopen("input.txt","r",stdin);
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
    reu(i,1,n) b[i]=a[_v[i]];
    f[1]=1;
    int r=1;
    c[r]=b[1];
    reu(i,2,n)
    {
        if (b[i]>=c[r]) c[++r]=b[i],f[i]=r; else
        {
            int vt=upper_bound(c+1,c+1+r,b[i])-c;
            f[i]=vt;
            c[vt]=b[i];
        }
    }
    cout<<n-*max_element(f+1,f+1+n);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    Proc();
    return 0;
}

