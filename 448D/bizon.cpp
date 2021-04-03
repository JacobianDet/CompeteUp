#include <bits/stdc++.h>

typedef long long ll;

ll bs1(ll n, ll m, ll k)
{
    ll lo = 1;
    ll hi = n*m;
    while(lo < hi)
    {
        ll mid = lo + (hi - lo)/2;
        ll mx = std::min(n, m), tot = 0;
        for(ll i=1;i<=mx;i++)
        tot += std::min(mid/i, ((mx == m) ? n : m));
        if(tot >= k)
        hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(void)
{
    ll n,m,k;
    std::cin>>n>>m>>k;
    ll ans = bs1(n, m, k);
    std::cout<<ans<<"\n";
    return 0;
}