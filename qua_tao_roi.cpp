#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
using namespace std;
void Enter()
{
    int n,m,j;
    cin>>n>>m;
    cin>>j;
    int curr=1;
    int res=0;
    while (j--)
    {
        int x;
        cin>>x;
        if (curr+m-1<x) {while (curr+m-1<x) {res++;curr++;} }
        if (x<curr) {while (x<curr) {res++;curr--;} }
    }
    cout<<res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
