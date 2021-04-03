#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001
#define MOD 1000000007

typedef long long ll;

ll arr[5001];
bool isP[CHOR];
std::vector<ll> px;
std::map<ll, ll> ctx;

void siever(void)
{
    memset(isP, 1, sizeof(isP));
    isP[0] = 0;
    isP[1] = 0;
    for(ll p=2;p*p<CHOR;p++)
    {
        if(isP[p])
        {
            for(ll i=p*p;i<CHOR;i+=p)
            isP[i] = 0;
        }
    }
    for(ll i=2;i<CHOR;i++)
    {
        if(isP[i])
        px.pb(i);
    }
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

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    siever();
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        ll t = arr[i];
        for(int j=0,k=(int)px.size();j<k;j++)
        {
            ll p = px[j];
            ll ctr = 0;
            while(!(t%p))
            {
                ctr++;
                t /= p;
            }
            if(ctr)
            ctx[p] += ctr;
        }
        if(t > 1)
        ctx[t]++;
    }
    bool ok = 0;
    for(std::map<ll, ll>::iterator it = ctx.begin();it != ctx.end();it++)
    {
        if(it->second % n)
        {
            ok = 1;
            break;
        }
    }
    if(!ok)
    std::cout<<"justdoit\n";
    else
    {
        ll ans = 1;
        for(std::map<ll, ll>::iterator it = ctx.begin();it != ctx.end();it++)
        {
            if((it->second)%(n+1))
            ans = ((ans%MOD) * (modexp(it->first, n - (it->second)%(n+1) + 1)%MOD))%MOD;
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}