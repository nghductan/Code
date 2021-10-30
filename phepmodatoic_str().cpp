#include <bits/stdc++.h>
#define ll long long
using namespace std;
void Solve()
{
    ll A,B,C;
    char z[20];
    string s="1234123";
    strcpy(z,s.c_str());
    ll h=atoi(z);
    cout<<h;
    exit(0);
    ll res=pow(10,s.size());
    int k=0;
    while (k<=6000)
    {
        ++k;
        A=(A*B)%res;
        if (A==C) cout<<k,exit(0);
    }
    cout<<"NO";
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
