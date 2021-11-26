#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define red(i,a,b) for (int i=a;i>=b;--i)
const int oo=0x3f3f3f3f;
using namespace std;
int f[30005][1005],a[30005],A,B,C,n,k,Right[30005];
int F[30005][1005];
int Magic(int i,int used)
{
    if (i==n) return 0;
    int res=oo;
    if (f[i][used]!=-1) return f[i][used];
    if (a[i]==a[i+1]) return f[i][used]=Magic(i+1,used)+A; else
    {
        res=min(res,Magic(i+1,used)+B);
        if (used<k)
        {
            if (Right[i]!=i) res=min(res,Magic(Right[i],used+1)+(Right[i]-i)*C);
        }
    }
    return f[i][used]=res;
}
void Proc()
{
    map<int,int> m;
    red(i,n,1)
    {
        if (m.count(a[i]))
        {
            Right[i]=m[a[i]];
        } else Right[i]=i;
        m[a[i]]=i;
    }
}
void Enter()
{
    freopen("input.txt","r",stdin);
    cin>>A>>B>>C;
    cin>>n>>k;
    memset(f,0xff,sizeof f);
    reu(i,1,n)
    {
        char ch;
        cin>>ch;
        if (ch=='R') a[i]=a[i-1]; else if (ch=='G') a[i]=a[i-1]+1; else a[i]=a[i-1]-1;
    }
    Proc();
 //   cout<<Magic(0,0);
    /*viet lai bang for */
    /*thay kq la 0,0 ->f[0,0] */
    /*chay n dau tien -> for i dau tien */
    red(i,n,0)
    red(j,k,0)
    {
        int &res=F[i][j];
        if (i==n) {res=0;continue;}
        res=oo;
        if (a[i]==a[i+1]) res=F[i+1][j]+A; else
        {
            res=min(res,F[i+1][j]+B);
            if (j<k && Right[i]!=i) res=min(res,F[Right[i]][j+1]+(Right[i]-i)*C);
        }
    }
    cout<<F[0][0];
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
