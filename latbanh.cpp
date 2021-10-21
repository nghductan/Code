#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //nướng n cái bánh có 2 mặt mỗi lần nướng 1 mặt được k cái bánh mất 5p
    ll n,k;
    cin>>n>>k;
    if (2*n%k==0) cout<<(2*n/k)*5; else cout<<(2*n/k)*5+5;
    return 0;
}
