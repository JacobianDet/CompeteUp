#include <bits/stdc++.h>
#define MOD 1000000007
#define CHOR1 2
#define CHOR2 500000003

typedef long long ll;

ll arr[5001], fact[5001];

ll modexp1(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%CHOR1) * (a%CHOR1))%CHOR1;
        a = ((a%CHOR1) * (a%CHOR1))%CHOR1;
        n >>= 1;
    }
    return res;
}

ll modexp2(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%CHOR2) * (a%CHOR2))%CHOR2;
        a = ((a%CHOR2) * (a%CHOR2))%CHOR2;
        n >>= 1;
    }
    return res;
}

ll modexpD(ll a, ll n)
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

//USE THIS TECHNIQUE ONLY IF MOD VALUE IS OUTSIDE RANGE
void factup(void)
{
    for(int i=0;i<5001;i++)
    fact[i] = 1;
    for(ll i=1;i<5001;i++)
    fact[i] = ((i%CHOR2) * (fact[i-1]%CHOR2))%CHOR2;
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
    while(T--)
    {
        int n,k;
        std::cin>>n>>k;
        for(int i=1;i<=n;i++)
        std::cin>>arr[i];
        std::sort(arr+1, arr+n+1);
        ll ans = 1;
        ll px = 0;
        ll am1 = 1;
        if((k-1) & (n-k))
        am1 = 0;
        ll am2 = ((((fact[n-1]%CHOR2) * (modexp2(fact[k-1], CHOR2-2)%CHOR2))%CHOR2) * (modexp2(fact[n-k], CHOR2-2)%CHOR2))%CHOR2;
        ll at1 = ((((am1%(MOD-1)) * ((1LL*CHOR2)%(MOD-1)))%(MOD-1)) * (modexp1(1LL*CHOR2, CHOR1-2)%(MOD-1)))%(MOD-1);
        ll at2 = ((((am2%(MOD-1)) * ((1LL*CHOR1)%(MOD-1)))%(MOD-1)) * (modexp2(1LL*CHOR1, CHOR2-2)%(MOD-1)))%(MOD-1);
        px = ((at1%(MOD-1)) + (at2%(MOD-1)))%(MOD-1);   
        for(int i=1;i<=n;i++)
        {
            ll st = 0;
            ll en = 0;
            if(i <= n-k+1)
            {
                ll ax1 = 1;
                if((k-1) & (n-i-k+1))
                ax1 = 0;
                ll ax2 = ((((fact[n-i]%CHOR2) * (modexp2(fact[k-1], CHOR2-2)%CHOR2))%CHOR2) * (modexp2(fact[n-i-k+1], CHOR2-2)%CHOR2))%CHOR2;
                ll av1 = ((((ax1%(MOD-1)) * ((1LL*CHOR2)%(MOD-1)))%(MOD-1)) * (modexp1(1LL*CHOR2, CHOR1-2)%(MOD-1)))%(MOD-1);
                ll av2 = ((((ax2%(MOD-1)) * ((1LL*CHOR1)%(MOD-1)))%(MOD-1)) * (modexp2(1LL*CHOR1, CHOR2-2)%(MOD-1)))%(MOD-1);
                st = ((av1%(MOD-1)) + (av2%(MOD-1)))%(MOD-1);
            }    
            if(i >= k)
            {
                ll ay1 = 1;
                if((k-1) & (i-k))
                ay1 = 0;
                ll ay2 = ((((fact[i-1]%CHOR2) * (modexp2(fact[k-1], CHOR2-2)%CHOR2))%CHOR2) * (modexp2(fact[i-k], CHOR2-2)%CHOR2))%CHOR2;
                ll au1 = ((((ay1%(MOD-1)) * ((1LL*CHOR2)%(MOD-1)))%(MOD-1)) * (modexp1(1LL*CHOR2, CHOR1-2)%(MOD-1)))%(MOD-1);
                ll au2 = ((((ay2%(MOD-1)) * ((1LL*CHOR1)%(MOD-1)))%(MOD-1)) * (modexp2(1LL*CHOR1, CHOR2-2)%(MOD-1)))%(MOD-1);  
                en = ((au1%(MOD-1)) + (au2%(MOD-1)))%(MOD-1); 
            }
            ll ap = ((((px%(MOD-1)) - (st%(MOD-1)) + (MOD-1))%(MOD-1)) - (en%(MOD-1)) + (MOD-1))%(MOD-1);
            ll ax = modexpD(arr[i], ap)%MOD;
            ans = ((ans%MOD) * (ax%MOD))%MOD;
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}