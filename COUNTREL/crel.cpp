#include <bits/stdc++.h>
#define MOD 100000007

typedef long long ll;

ll modexp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%MOD) * (a%MOD))%MOD;
        a = ((a%MOD) * (a%MOD))%MOD;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        ll n;
        std::cin>>n;
        ll a1 = modexp(4, n)%MOD;
        ll a2 = modexp(3, n)%MOD;
        ll a3 = modexp(2, n)%MOD;
        ll r1 = ((((((a2%MOD) * (modexp(2, MOD-2)%MOD))%MOD) - (a3%MOD) + MOD)%MOD) + (modexp(2, MOD-2)%MOD))%MOD;
        ll r2 = ((((((((a1%MOD) * (modexp(2, MOD-2)%MOD))%MOD) - (((((3%MOD) * (a2%MOD))%MOD) * (modexp(2, MOD-2)%MOD))%MOD) + MOD)%MOD) + (((((3%MOD) * (a3%MOD))%MOD) * (modexp(2, MOD-2)%MOD))%MOD))%MOD) - (modexp(2, MOD-2)%MOD) + MOD)%MOD;     
        std::cout<<r1<<" "<<r2<<"\n";
    }
    return 0;
}