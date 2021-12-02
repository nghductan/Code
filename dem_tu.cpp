#include <bits/stdc++.h>

using namespace std;
bool check(char ch)
{
    if (ch==',' || ch=='.' || ch==' ') return 0;
    return 1;
}
void Enter()
{
    string s;
    getline(cin,s);
    bool ok=1;
    int res=0;
    for (int i=0;i<s.size();i+=1)
    {
        if (check(s[i])==1 && ok==1) res++,ok=0; else if (check(s[i])==0 && ok==0) ok=1;
    }
    cout<<res;
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
