#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
#define fi first
#define se second

using namespace std;
typedef pair<string,string> pss;
map<string,string> m;

string spinR(string s)
{
    char tmp=s.back();
    s.pop_back();
    s=tmp+s;
    return s;
}
string spinS(string s)
{
    swap(s[0],s[1]);
    return s;
}
void bfs()
{
    queue<string> q;
    q.push("1234");
    m["1234"]="";
    while (q.size())
    {
       if (m.size()==24) break;
        string u=q.front();
        q.pop();
        string tmpR=spinR(u);
        string tmpS=spinS(u);
        if (!m.count(tmpR))
        {
            m[tmpR]=m[u]+'R';
            q.push(tmpR);
        }
        if (!m.count(tmpS))
        {
            m[tmpS]=m[u]+'S';
            q.push(tmpS);
        }
    }
}
void Enter()
{
    freopen("input.txt","r",stdin);
    string tc;
    cin>>tc;
    string status="1234";
    reu(i,0,tc.size()-1) if (tc[i]=='R') status=spinR(status); else status=spinS(status);

    bfs(); // sinh theo thứ tự từ điển nhỏ đến lớn
    cout<<m[status];
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
