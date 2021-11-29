#include <bits/stdc++.h>

using namespace std;
stack<char> st;
void Enter()
{
   string s;
    cin>>s;
    int res=0;
    for (int i=0;i<s.size();i+=1)
    {
        if (s[i]==']' || s[i]=='}' || s[i]=='>' || s[i]==')')
        {if (!st.size()) cout<<-1,exit(0); if ((int)st.top()==(int)s[i]-2 || (int) st.top()==(int)s[i]-1) st.pop(); else res++,st.pop(); } else st.push(s[i]);
    }
    if (st.size()) cout<<-1; else cout<<res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
