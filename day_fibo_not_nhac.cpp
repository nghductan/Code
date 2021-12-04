#include <bits/stdc++.h>

using namespace std;
int f[50];
char FF[8]={'#','C','D','E','F','G','A','B'};
void Enter()
{
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=45;i+=1) f[i]=f[i-1]+f[i-2];
    int u,v;
    cin>>u>>v;
    for (int i=u;i<=v;i+=1) cout<<FF[(f[i]-1)%7+1]<<' ';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    Enter();
    return 0;
}
