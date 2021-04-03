#include <bits/stdc++.h>
#define MOD 1000000007

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
        std::string s;
        std::cin>>s;
        int n = (int)s.size();
        ll x = 0, p = 0;
        for(int i=0;i<n;i++)
        p = ((((10%MOD) * (p%MOD))%MOD) + ((s[i] - '0')%MOD))%MOD;
        ll z = modexp(10, n)%MOD;
        for(int i=0;i<n;i++)
        {
            x = ((((z%MOD) * (x%MOD))%MOD) + (p%MOD))%MOD;
            p = ((((((10%MOD) * (p%MOD))%MOD) - ((((s[i] - '0')%MOD) * (z%MOD))%MOD) + MOD)%MOD) + ((s[i] - '0')%MOD))%MOD;
        }
        std::cout<<x<<"\n";
    }
    return 0;
}