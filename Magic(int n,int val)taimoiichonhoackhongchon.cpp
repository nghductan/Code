#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[18],Q[131072],r=0; //tong to hop 18 chap x
void Magic(int n,ll val)
{
    if (n==0)
    {
        Q[r++]=val;
        return;
    }
    Magic(n-1,val);
    Magic(n-1,val+f[n]);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0]=1;
    for (int i=1;i<=17;++i) f[i]=f[i-1]*5;
    Magic(17,0);
    int n;
    cin>>n;
    cout<<Q[n];
    return 0;
}
