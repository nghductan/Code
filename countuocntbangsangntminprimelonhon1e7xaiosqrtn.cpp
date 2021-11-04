#include <bits/stdc++.h>
#define ll long long
using namespace std;
int minprime[10000007];
ll cnt(ll x)
{
    ll i=2,res=0;
    if (x>1e7)
    {
    while (i<=sqrt(x))
    {
        if (x%i==0) {res++;while (x%i==0) x/=i;}
            i++;
    }
    if (x!=1) res++;
    } else
    {
        ll p=0;
        while (x!=1)
        {
            if (p!=minprime[x]) res++,p=minprime[x];
            x/=minprime[x];
        }
    }
    return res;
}
void snt()
{
    for (int i=2;i<=sqrt(10000000);++i)
    {
        if (minprime[i]==0)
            for (int j=i*i;j<=10000000;j+=i) if (minprime[j]==0) minprime[j]=i;
    }
    for (int i=2;i<=10000000;++i) if (minprime[i]==0) minprime[i]=i;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    snt();
    while (t--)
    {
        ll x;
        cin>>x;
        cout<<cnt(x)<<'\n';
    }
    return 0;
}
