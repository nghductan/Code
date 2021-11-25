#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
const int oo=0x3f3f3f3f;
int d[150],f[150],n,A,B,C;
using namespace std;
void Enter()
{
    freopen("input.txt","r",stdin);
    cin>>n>>A>>B>>C;
    int maxK=0,sum=0,ans=oo,diff;
    string ans_string="";
    reu(i,1,n)
    {
        cin>>d[i];
        sum+=d[i];
        maxK=max(maxK,d[i]);
    }
    f[n]=d[n];
    for (int i=n-1;i>=1;i--) f[i]=d[i]+f[i+1];
 //   reu(i,1,n) cout<<f[i]<<' ';
  // exit(0);
    reu(k,maxK,sum)
    {
        int tmp=k*A;  string tmp_string="";
        int currK=k;
        reu(i,1,n)
        {
            if (tmp>=ans) break;
            if (currK>=f[i])
            {
                ans=tmp;
                ans_string=tmp_string;
                reu(j,i,n)
                {
                    ans_string+="0 0 0\n";
                }
            }
            if (i==1) tmp_string+=to_string(k)+' '; else tmp_string+="0 ";
            currK-=d[i];
            if (i+1<=n && currK<d[i+1])
            {
                diff=d[i+1]-currK;
                tmp_string+=to_string(diff)+' ';
                tmp+=diff*B;
                currK+=diff;
            } else tmp_string+="0 ";
            if (i+1<=n &&k>=f[i+1])
            {
                diff=f[i+1]-currK;
                if (diff>=0)
                {
                    tmp+=diff*C;
                    tmp_string+=to_string(diff)+'\n';
                    currK+=diff;
                }
            } else
            {
                diff=k-currK;
                tmp_string+=to_string(diff)+'\n';
                tmp+=C*diff;
                currK=k;
            }
        }
    }
    cout<<ans<<'\n'<<ans_string;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    Enter();
    return 0;
}
