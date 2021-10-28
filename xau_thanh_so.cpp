#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll _xauso(string s)
{
    ll ans=0;
    for (auto x:s) ans=ans*10+x-'0';
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<_xauso(s);
    return 0;
}
