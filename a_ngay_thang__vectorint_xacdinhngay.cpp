#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int N=200;
using namespace std;
int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> m;
vector<int> a[N][N];
int n;
void Enter()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    string s,ch,s1,s2,s3;
    cin>>s>>ch;
    if (ch=="yes") d[2]++;
    m["monday"]=0;
    m["tuesday"]=1;
    m["wednesday"]=2;
    m["thursday"]=3;
    m["friday"]=4;
    m["saturday"]=5;
    m["sunday"]=6;
    m["january"]=1;
    m["february"]=2;
    m["march"]=3;
    m["april"]=4;
    m["may"]=5;
    m["june"]=6;
    m["july"]=7;
    m["august"]=8;
    m["september"]=9;
    m["october"]=10;
    m["november"]=11;
    m["december"]=12;
    int _count=m[s];
    reu(i,1,12)
    {
        int cnt=1;
        while (cnt<=d[i])
        {
            a[(_count++)%7][i].push_back(cnt++);
        }
    }
    for (;n--;)
    {
        cin>>s>>s1>>s2>>s3;
        if (s=="last") cout<<a[m[s1]][m[s3]].back()<<'\n'; else cout<<a[m[s1]][m[s3]].front()<<'\n';
    }

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
