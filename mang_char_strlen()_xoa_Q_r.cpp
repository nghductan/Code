#include <bits/stdc++.h>

using namespace std;

int main()
{
    char Q[1000],a[1000];
    cin>>a;
    int r=0;
    int n=strlen(a);
    for (int i=0;i<n;++i)
    {
        if (r>0 && Q[r]==a[i]) r--;else Q[++r]=a[i];
    }
    /*abzxxzc
    b1: r=1,i=0 -> a
    b2: i=1,a[1]==Q[1] ? ->no -> r=2 ->ab
    b3: i=2,r=2->b==z? ->no ->r=3->abz
    b4:i=3,r==3->z==x?->no->r=4->abzx
    b5: i=4,r=4->x==x?->r=3->abz
    b6:i=5,r=3->z==z?->r=2->ab
    b7:i=6,r=2->b==c?->r=3->abc */
    for (int i=1;i<=r;++i) cout<<Q[i];
    return 0;
}
