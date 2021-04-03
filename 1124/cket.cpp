#include <bits/stdc++.h>
#define MOD 100000007

typedef long long ll;

ll arr[11], factx[1000001], invf[1000001];

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

void factup(void)
{
    factx[0] = 1;
    invf[0] = 1;
    for(ll i=1;i<1000001;i++)
    {
        factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
        invf[i] = modexp(factx[i], MOD-2);
    }
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    factup();
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        ll n;
        int k;
        std::cin>>k>>n;
        ll up1 = 0, up2 = n;
        for(int i=0;i<k;i++)
        {
            ll f,F;
            std::cin>>f>>F;
            n -= f;
            arr[i] = F-f+1;
            up1 += F;
        }
        if((n < 0) || (up2 > up1))
        std::cout<<"Case "<<t<<": 0\n";
        else
        {
            ll ans = 0;
            for(int i=0;i<(1<<k);i++)
            {
                ll sx = 0;
                for(int j=0;j<k;j++)
                {
                    if(i & (1<<j))
                    sx += arr[j];
                }
                if((n - sx) >= 0)
                {
                    if(__builtin_popcount(i) & 1)
                    ans = ((ans%MOD) - (((((factx[n+k-sx-1]%MOD) * (invf[n-sx]%MOD))%MOD) * (invf[k-1]%MOD))%MOD) + MOD)%MOD;
                    else ans = ((ans%MOD) + (((((factx[n+k-sx-1]%MOD) * (invf[n-sx]%MOD))%MOD) * (invf[k-1]%MOD))%MOD))%MOD;
                }    
            }
            std::cout<<"Case "<<t<<": "<<ans<<"\n";
        }
    }
    return 0;
}