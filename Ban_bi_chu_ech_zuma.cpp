#include <bits/stdc++.h>

using namespace std;
void Enter()
{
    string s;
    int vt; char ch;
    cin>>s;
    cin>>vt>>ch;
    string left=s.substr(0,vt-1)+ch;
    string right=s.substr(vt-1,s.size()-(vt-1));
    int n=left.size();
    int m=right.size();
    int ans=0;
    while (true)
    {
        if (!left.size() || !right.size()) break;
        if (left[n-1]==right[0])
        {
            char tmp=left[n-1];
            while (left.size() &&left[n-1]==tmp) left.erase(n-1,1),n--,ans++;
            while (right.size()&& right[0]==tmp) right.erase(0,1),ans++;
        } else break;
    }
    cout<<ans;
}
int main()
{
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
