#include <bits/stdc++.h>
#define BIT(x, i) (((x)>>(i))&1)
#define MASK(i) (1LL<<(i))
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define TASK "test"

using namespace std;
typedef long long ll;
typedef  double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template<typename T1, typename T2> bool mini(T1 &a, T2 b) {if(a>b) a=b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {if(a<b) a=b; else return 0; return 1;}
template<typename T1> T1 abs(T1 a) {if(a<0) a*=-1; return a;}
ll Rand(ll a, ll b){return a + ll(rand()) * rand() % (b-a+1);}

const int N = 305;
const ld oo = 1.0/0;

int n, m, k, a[N], b[N];
ll l;
bool d[N][N][N];
ld f[N][N][N];

double Magic(int i,int j,int _count)
{
    if (i>n || j>m)
    {
        if (_count==k) return 0; else return oo;
    }
    if (d[i][j][_count]) return f[i][j][_count];
    d[i][j][_count]=1;
    return f[i][j][_count]=min({Magic(i+1,j,_count),Magic(i,j+1,_count),Magic(i+1,j+1,_count+1)+sqrt(l*l+pow(a[i]-b[j],2))});
}

void proc()
{
    cin>>n>>m>>l>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for (int i=n+1;i>=1;i--)
    for (int j=m+1;j>=1;j--)
    for (int z=k;z>=0;z--)
    {
        if (i>n ||j>m)
        {
            if (z==k) f[i][j][z]=0; else f[i][j][z]=oo;
            continue;
        }
        f[i][j][z]=min({f[i][j+1][z],f[i+1][j][z],f[i+1][j+1][z+1]+sqrt(l*l+pow(a[i]-b[j],2))});
    }
    cout<<setprecision(6)<<fixed<<f[1][1][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
  //  freopen("input.txt","r",stdin);
    int t=1; //cin>>t;
    while(t--)
    {
        proc();
    }
    return 0;
}
