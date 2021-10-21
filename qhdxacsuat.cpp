#include <bits/stdc++.h>
#define db double
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=3e3;

using namespace std;
db f[N][N],p[N];
int n;

int main()
{
    cin>>n;
    reu(i,1,n) cin>>p[i];
    //GỌI F[I][J] LÀ TỔNG XÁC SUẤT ĐỂ TUNG I ĐỒNG XU MÀ ĐƯỢC J MẶT NGỬA
    //f[0][0]=100%=1
    f[0][0]=1.0;
    reu(i,1,n)
    reu(j,0,i)
    {
        if (j!=0) f[i][j]=f[i-1][j]*(1-p[i])+f[i-1][j-1]*p[i]; else f[i][j]=f[i-1][j]*(1-p[i]);
    }
    db ans=0.0;
    reu(i,n/2+1,n) ans+=f[n][i];
    cout<<fixed<<setprecision(9)<<ans;
    return 0;
}
