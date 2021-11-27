#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
using namespace std;
map<char,int> m;
int main()
{
    string s;
    cin>>s;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    int i=0;
    int res=0;
  //  map<string,int> m;
    while (i<s.size())
    {
        if (m[s[i]]<m[s[i+1]]) res-=m[s[i]]; else res+=m[s[i]];
        ++i;
    }
    cout<<res;
    return 0;
}
