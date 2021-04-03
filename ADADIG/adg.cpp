#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int arr[10];
ll factx[1000001];
std::map<ll, ll> ax;
bool px[300001];

void siever(void)
{
    memset(px, 1, sizeof(px));
    px[0] = 0;
    px[1] = 0;
    for(int p=2;p*p<300001;p++)
    {
        if(px[p])
        {
            for(int i=p*p;i<300001;i+=p)
            px[i] = 0;
        }    
    }
    return;
}

void factup(void)
{
    for(int i=0;i<1000001;i++)
    factx[i] = 1;
    for(int i=1;i<1000001;i++)
    factx[i] = (((1LL*i)%MOD) * (factx[i-1]%MOD))%MOD;
    return;
}

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

ll recz(int sum, int prod, int ld)
{
    if((!sum && prod > 1) || (prod > 9 && px[prod]))
    return 0;
    else if(!sum && (prod == 1))
    {
        int tc = 0;
        for(int i=1;i<=9;i++)
        tc += arr[i];
        ll ans = factx[tc]%MOD;
        for(int i=1;i<=9;i++)
        {
            if(arr[i])
            ans = ((ans%MOD) * (modexp(factx[arr[i]], MOD-2)%MOD))%MOD;
        }    
        return ans;
    }
    ll ans = 0;
    if(prod > 1 && sum > 0)
    {
        for(int i=2;i<=ld;i++)
        {
            if(!(prod % i) && ((sum - i) >= 0))
            {
                arr[i]++;
                ans = ((ans%MOD) + (recz(sum-i, prod/i, i)%MOD))%MOD;
                arr[i]--;
            }    
        }
    }
    if(sum > 0 && prod == 1)
    {
        arr[1] += sum;
        ans = ((ans%MOD) + (recz(0, prod, 1)%MOD))%MOD;
        arr[1] -= sum;
    }    
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    siever();
    factup();
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        if(ax[n])
        std::cout<<ax[n]<<"\n";
        else
        {
            ll ctx = recz(n, n, 9);
            std::cout<<ctx<<"\n";
            ax[n] = ctx;
        }    
    }
    return 0;
}