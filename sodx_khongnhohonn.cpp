#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
using namespace std;
string increase(string s)
{
    int tmp=1;
    for (int i=s.size()-1;i>=0;--i)
    {
        int x=s[i]-'0'+tmp;
        tmp=x/10;
        s[i]=(char)(x%10+'0');
    }
    if (tmp) s='1'+s;
    return s;
}
int main()
{
    string s;
    cin>>s;
    string z=s;
    for (int i=0;i<=z.size()-1;++i) z[z.size()-1-i]=z[i];
    if (z>s) cout<<z,exit(0);
    string dx="";
    for (int i=0;i<=(s.size()-1)/2;i++) dx+=s[i];
    s.erase(0,dx.size());
    string th101=increase(dx);
    if (th101.size()>dx.size()) {s=th101+s; for (int i=0;i<=(s.size()-1)/2;++i) s[s.size()-1-i]=s[i]; cout<<s;} else
    {
        s=th101+s;
        for (int i=0;i<=(s.size()-1)/2;++i) s[s.size()-1-i]=s[i];
        cout<<s;
    }
    return 0;
}
