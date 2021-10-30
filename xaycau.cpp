#include <bits/stdc++.h>
#define ll long long
const int N=3e4+1;
using namespace std;
ll A,B,C,a[N],Next[N],n,k,f[N][1001];
void Enter()
{
    cin>>A>>B>>C;
    cin>>n>>k;
    ll res=0;
    a[0]=0;
    for (int i=1;i<=n;++i)
    {
        char ch; cin>>ch;
        if (ch=='R') a[i]=res; else if (ch=='G') res++,a[i]=res; else res--,a[i]=res;
    }
}
void Init()
{
    //tính trước vị trí xây câu hoặc hầm tiếp theo khi a[x]=a[Right[x]] và a[x]!=x[x+1]
    map<ll,ll> m;
    for (int i=n;i>=0;--i)
    {
        if (!m.count(a[i])) Next[i]=i; else Next[i]=m[a[i]];
        m[a[i]]=i;
    }
}
ll Magic(int i, int used)
{
    if (i==n) return 0;
    ll res=1e15;
    if (a[i]==a[i+1]) res=Magic(i+1,used)+A; else
    {
        res=min(res,Magic(i+1,used)+B);
        if (Next[i]!=i&& used<k) {res=min(res,Magic(Next[i],used+1)+(Next[i]-i)*C);}
    }
    return res;
}
void SolveMagic()
{
    cout<<Magic(0,0);
}
void SolveCopMagic()
{
//    kết quả là f[0][0] và f[i][used] được tính từ f[i+1][used+1] hoặc là f[i+1][used] -> for ngược tính f[0][0]
    for (int i=n;i>=0;--i)
    for (int used=k;used>=0;used--)
    {
        ll &res=f[i][used];
        if (i==n)
        {
            res=0;
            continue;
        }
        res=1e15;
        if (a[i]==a[i+1]) res=f[i+1][used]+A; else
        {
            res=min(res,f[i+1][used]+B);
            if (Next[i]!=i && used<k )res=min(res,f[Next[i]][used+1]+(Next[i]-i)*C);
        }
    }
    cout<<f[0][0];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    Enter();
    Init();
    //SolveMagic();
    SolveCopMagic();
    return 0;
}
