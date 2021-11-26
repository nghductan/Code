#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)

using namespace std;
int ans=0,n,k;
set<int> s;
map<int,int> sl;
map<int,bool> m;
int main()
{
    cin>>n>>k;
    int x;
    /*reu(i,1,n) cin>>x,s.insert(x),sl[x]++;
    for (auto x:s)
    {
        if (!m.count(x))
        {
            if (2*x==k) ans+=sl[x]*(sl[x]-1)/2; else
            {
                auto it=s.lower_bound(k-x);
                if (*it==k-x)
                {
                    m[k-x]=1;
                    ans+=sl[k-x]*sl[x];
                }
            }
        }
    }
    cout<<ans;*/
    reu(i,1,n)
    {
        cin>>x;
        ans+=sl[k-x]; sl[x]++;
    }
    cout<<ans;
    return 0;
}
