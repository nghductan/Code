#include <bits/stdc++.h>

using namespace std;
void Enter()
{
    long long n;
    cin>>n;
    int d=log10(n)+1; //d<=18
    cout<<d<<'\n';
}
bool isPrime(long long n)
{
    if (n==2 || n==3) return true;
    if (n<2 || n%2==0 || n%3==0) return false;
    for (long long i=6;i<=(sqrt(n)+1);i+=6) if (n%(i+1)==0 || n%(i-1)==0) return false;
    return true;
}
int main()
{
    /*   LẤY SỐ CHỮ SỐ N =LOG10(N)+1    */
    /* KIỂM TRA SỐ NGUYÊN TỐ LOẠI CÁC SỐ 6K,6K+2,6K+3,6K+4 -> CHỈ KIỂM TRA 6K+1,6K+5 (6K-1) NHỚ XÉT SỐ 25(TẠI I=6,QSRT(N)+1*/
    Enter();
    cout<<isPrime(41242);
    return 0;
}
