#include <bits/stdc++.h>
#define ll long long
#define reu(i,a,b) for (int i=a;i<=b;++i)
using namespace std;
set<ll> s;
 int n;
int main()
{
    string s;
    cin>>s;
    bool check;
    int i=0;
    while (i<=(int)s.size()-1)
    {
        check=0;
        if (i+1>=0 && (i+1<=s.size()-1) &&s[i]==s[i+1]) {s.erase(i,2),check=1,i=i-1;}
        if (check==0) i++;
        if (!s.size()) break;
    }
  cout<<s;
    return 0;
}
