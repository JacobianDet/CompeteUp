#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll F[(1<<21)], G[(1<<21)], H[(1<<21)], T[(1<<21)];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=0;i<(1<<n);i++)
    std::cin>>F[i];
    for(int i=0;i<(1<<n);i++)
    std::cin>>G[i];
    for(int i=0;i<(1<<n);i++)
    std::cin>>H[i];
    for(int p=0;p<n;p++)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(mask & (1<<p))
            {
                F[mask] += F[mask ^ (1<<p)];
                if(F[mask] >= MOD)
                F[mask] -= MOD;
                G[mask] += G[mask ^ (1<<p)];
                if(G[mask] >= MOD)
                G[mask] -= MOD;
                H[mask] += H[mask ^ (1<<p)];
                if(H[mask] >= MOD)
                H[mask] -= MOD;
            }
        }
    }
    for(int i=0;i<(1<<n);i++)
    {
        T[i] = ((F[i]%MOD) * (G[i]%MOD))%MOD;
        T[i] = ((T[i]%MOD) * (H[i]%MOD))%MOD;
    }
    for(int p=0;p<n;p++)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(mask & (1<<p))
            {
                T[mask] -= T[mask ^ (1<<p)];
                if(T[mask] < 0)
                T[mask] += MOD;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<(1<<n);i++)
    {
        int b = __builtin_popcount(i);
        ans += ((T[i]%MOD) * ((1LL<<b)%MOD))%MOD;
        if(ans >= MOD)
        ans -= MOD;
    }
    std::cout<<ans<<"\n";
    return 0;
}