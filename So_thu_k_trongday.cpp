#include <bits/stdc++.h>
#define ll long long
#define reu(i,a,b) for (int i=a;i<=b;++i)

const int oo=0x3f3f3f3f;
using namespace std;
vector<ll> res;
int tknp(int n)
{
    int l=1,r=100000;
    int  ok=1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (mid*n>res.back()) {r=mid-1;ok=mid;} else l=mid+1;
    }
    return ok;
}
void Enter()
{
    int k;
    cin>>k;
    res.push_back(1);
    reu(i,2,1000000)
    {
        if (res.size()>=k) cout<<res[k-1],exit(0);
        int vt=tknp(i);
        reu(j,vt,vt+i-1) res.push_back(j*i);
    }
}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
