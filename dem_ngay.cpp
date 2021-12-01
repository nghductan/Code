#include <bits/stdc++.h>
#define reu(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int xau_so(string s)
{
    int res=0;
    for (int i=0;i<s.size();i+=1)
    {
        res=res*10+s[i]-'0';
    }
    return res;
}
void check(int n)
{
    int i=2,res=0,m=n;
    while (i--)
    {
        res+=m%10;
        m/=10;
    }
    if (res==0) {if (n%400==0) d[2]=29; else d[2]=28; return;}
    if (n%4==0) d[2]=29; else d[2]=28;
    return;
}
void Enter()
{
    freopen("input.txt","r",stdin);
    string s,s1;
    cin>>s>>s1;
    if (s.size()<10) s.insert(s.begin()+3,'0');
     if (s1.size()<10) s1.insert(s1.begin()+3,'0');
    int day_start=xau_so(s.substr(0,2));
    int month_start=xau_so(s.substr(3,2));
    int year_start=xau_so(s.substr(6,4));

    int day_stop=xau_so(s1.substr(0,2));
    int month_stop=xau_so(s1.substr(3,2));
    int year_stop=xau_so(s1.substr(6,4));
    check(year_start);
    int res=0;
    while (1)
    {

        if (day_start==day_stop && month_start==month_stop && year_start==year_stop ) cout<<res,exit(0);

        if (day_start<d[month_start]) day_start++; else
        {
            if (month_start<12)
            {
                day_start=1;
                month_start++;
            } else
            {
                year_start++;
                check(year_start);
                day_start=month_start=1;
            }
        }
        res++;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
