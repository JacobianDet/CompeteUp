#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll factx[20], nm[10], rex[10];
ll per;
std::vector<std::vector<ll> > Z;

void factup(void)
{
    factx[0] = 1;
    for(ll i=1;i<20;i++)
    factx[i] = i*factx[i-1];
    return;
}

void perm_get(ll& x, int d)
{
    if(d == 10)
    {
        for(int i=0;i<10;i++)
        Z[x].pb(rex[i]);
        x++;
        return;
    }
    if(x == per)
    return;
    if(!nm[d])
    perm_get(x, d+1);
    else
    {
        for(ll i=1;i<=nm[d];i++)
        {
            rex[d] = i;
            perm_get(x, d+1);
        }
        rex[d] = 1;
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
    ll temp = n;
    while(temp)
    {
        nm[temp % 10]++;
        temp /= 10;
    }
    per = 1;
    for(int i=0;i<10;i++)
    {
        if(nm[i])
        per *= nm[i];
    }
    ll x = 0;
    Z.resize(per);
    perm_get(x, 0);
    ll ans = 0;
    for(ll i=0;i<per;i++)
    {
        ll tct = 0;
        for(int j=0;j<10;j++)
        tct += Z[i][j];
        if(Z[i][0])
        {
            ll a1 = factx[tct];
            for(int j=0;j<10;j++)
            a1 /= factx[Z[i][j]];
            ll a2 = factx[tct-1];
            a2 /= (factx[Z[i][0]-1]);
            for(int j=1;j<10;j++)
            a2 /= factx[Z[i][j]];
            ans += (a1 - a2);
        }
        else
        {
            ll a1 = factx[tct];
            for(int j=0;j<10;j++)
            a1 /= factx[Z[i][j]];
            ans += a1;
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}
