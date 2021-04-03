#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

ll factx[1000001], invf[1000001];

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
    	invf[i] = modexp(factx[i], MOD-2)%MOD;
    }	  
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    factup();
    ll n;
    std::cin>>n;
    ll ax = 0;
    for(int i=1;i<n;i++)
    ax = ((ax%MOD) + (((factx[n]%MOD) * (invf[i]%MOD))%MOD))%MOD;
    ll ans = ((((n%MOD) * (factx[n]%MOD))%MOD) - (ax%MOD) + MOD)%MOD;
    std::cout<<ans<<"\n";	
    return 0;
}