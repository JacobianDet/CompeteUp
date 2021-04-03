#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

ll n;
ll memo[1001], arr[1001], factx[1001];

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
    for(int i=0;i<=1000;i++)
    factx[i] = 1;
    for(ll i=1;i<=1000;i++)
    factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
    return;
}

ll fxc(ll i)
{
    if(i == n)
    return 0;
    if(memo[i] != -1)
    return memo[i];
    ll ans = 0;
    if(arr[i] > 0 && arr[i] <= n-i)
    {
        for(ll j=i+arr[i];j<=n;j++)
        {
            ll tx = 1;
            if((j-i-1) && (arr[i]-1) && ((j-i-1) != (arr[i]-1))) 
            tx = ((factx[(j-i-1)]%MOD) * (((modexp(factx[arr[i]-1], MOD-2)%MOD) * (modexp(factx[(j-i-arr[i])], MOD-2)%MOD))%MOD))%MOD;
            if(j+1 <= n)
            ans = ((ans%MOD) + (((tx%MOD) * ((fxc(j+1)%MOD) + (1%MOD))%MOD)%MOD))%MOD;
            else ans = ((ans%MOD) + (tx%MOD))%MOD;
        }
    }
    ans = ((ans%MOD) + (fxc(i+1)%MOD))%MOD;
    memo[i] = ans;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    factup();
    std::cin>>n;
    for(ll i=1;i<=n;i++)
    std::cin>>arr[i];
    ll ans = fxc(1LL)%MOD;
    std::cout<<ans<<"\n";
    return 0;
}