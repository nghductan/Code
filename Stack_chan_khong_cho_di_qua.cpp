#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define reud(i,a,b) for (int i=a;i>=b;--i)
const int N=1e5+7;
using namespace std;
stack<int> st;
int n,m,a[N],b[N];
void Enter()
{
    cin>>n>>m;
    reu(i,1,n) cin>>a[i];
    reu(i,1,m) cin>>b[i];
    reud(i,n,1)
    {
        while (m>0 &&a[i]<=b[m]) {st.push(m); m--;}
        if (!st.size()) {a[i]=-1; continue;}
        a[i]=st.top();
        st.pop();
    }
    reu(i,1,n) cout<<a[i]<<'\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
