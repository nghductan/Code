#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)

using namespace std;
pair<int,int> _next(int ch,int x,int y)
{
    if (ch=='U') y++;
    if (ch=='D') y--;
    if (ch=='L') x--;
    if (ch=='R') x++;
    return {x,y};
}
map<int,map<int,int>> check;
void Enter()
{
   // freopen("input.txt","r",stdin);
    int X,Y,n;
    vector<int> res;
    cin>>X>>Y;
    check[X-1][Y]=check[X][Y]=check[X+1][Y]=check[X+1][Y+1]=check[X-1][Y-1]=check[X+1][Y-1]=check[X-1][Y+1]=check[X][Y+1]=check[X][Y-1]=1;
    cin>>n;
    int ans=0,XX=0,YY=0;
    if (check[XX][YY]) res.push_back(ans);
    while (n--)
    {
        ans++;
        char ch;
        cin>>ch;
        pair<int,int> v=_next(ch,XX,YY);
        XX=v.first; YY=v.second;
        if (check[XX][YY]) res.push_back(ans);
    }
    if (!res.size()) cout<<-1,exit(0);
    for (auto x:res) cout<<x<<'\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
