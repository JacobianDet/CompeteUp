#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

int n;
ll memo[1001][2001][1<<2];

ll ballia(int i, int k, int mask)
{
    if(k < 0)
    return 0;
    else if(i == n)
    {
        if(!k)
        return 1;
        else return 0;
    }
    if(memo[i][k][mask] != -1)
    return memo[i][k][mask];
    ll ans = 0;
    if(!i)
    {
        for(int nx=0;nx<4;nx++)
        {
            if(__builtin_popcount(nx) & 1)
            ans = ((ans%MOD) + (ballia(i+1, k-2, nx)%MOD))%MOD;
            else ans = ((ans%MOD) + (ballia(i+1, k-1, nx)%MOD))%MOD;
        }
    }
    else
    {
        for(int nx=0;nx<4;nx++)
        {
            if(!(__builtin_popcount(nx) & 1))
            {
                if((nx ^ mask) == 3)
                ans = ((ans%MOD) + (ballia(i+1, k-1, nx)%MOD))%MOD;
                else ans = ((ans%MOD) + (ballia(i+1, k, nx)%MOD))%MOD;
            }
            else
            {
                if((nx ^ mask) == 3)
                ans = ((ans%MOD) + (ballia(i+1, k-2, nx)%MOD))%MOD;
                else if(!(nx ^ mask))
                ans = ((ans%MOD) + (ballia(i+1, k, nx)%MOD))%MOD;
                else ans = ((ans%MOD) + (ballia(i+1, k-1, nx)%MOD))%MOD;
            }
        }
    }
    memo[i][k][mask] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int k;
    std::cin>>n>>k;
    ll ans = ballia(0, k, 0)%MOD;
    std::cout<<ans<<"\n";
    return 0;
}
