#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=101;
const int _time=1e6;
using namespace std;
deque<pair<char,pair<int,int>>> dq;
bool check[N][N],a[N][N];
char s[_time];
int n,m,k;
pair<char,pair<int,int>> _next(char c,int x,int y, int z)
{
    char h;
    if (c=='E')
    {
        if (s[z]=='T') {y++;h='E';}
        if (s[z]=='L') {x--;h='N';}
        if (s[z]=='D') {x++;h='S';}
    }
    if (c=='N')
    {
        if (s[z]=='T') {x--;h='N';}
        if (s[z]=='L') {y--;h='W';}
        if (s[z]=='D') {y++;h='E';}
    }
    if (c=='W')
    {
        if (s[z]=='T') {y--;h='W';}
        if (s[z]=='L') {x++;h='S';}
        if (s[z]=='D') {x--;h='N';}
    }
    if (c=='S')
    {
        if (s[z]=='T') {x++;h='S';}
        if (s[z]=='L') {y++;h='E';}
        if (s[z]=='D') {y--;h='W';}
    }
    return {h,{x,y}};
}
bool kt(int x,int y)
{
    if (x<1 || x>n || y<1 || y>n) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    reu(i,1,k) {int x,y; cin>>x>>y; a[x][y]=1;}
    cin>>m;
    reu(i,0,_time) s[i]='T';
    reu(i,1,m) {int x;char c; cin>>x>>c; s[x]=c;}
    int ans=0;
    dq.push_front({'E',{1,1}});
    check[1][1]=1;
    while(true)
    {
        char ch=dq.front().first;
        int x=dq.front().second.first;
        int y=dq.front().second.second;
        pair<char,pair<int,int>> ne=_next(ch,x,y,ans);
        if (check[ne.second.first][ne.second.second] || !kt(ne.second.first,ne.second.second)) break;
        check[ne.second.first][ne.second.second]=1;
        dq.push_front({ne.first,{ne.second.first,ne.second.second}});
        if (a[ne.second.first][ne.second.second]==1)
        {
            a[ne.second.first][ne.second.second]=0;
        } else
        {
            check[dq.back().second.first][dq.back().second.second]=0;
            dq.pop_back();
        }
        ans++;
    }
    cout<<ans+1;
    return 0;
}
