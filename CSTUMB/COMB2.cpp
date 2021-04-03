#include <bits/stdc++.h>
#define INF 1000000000000001

typedef long long ll;

ll pref[102][100002], memo[102][1002], mxd[102][1002];
bool vis[102][1002];
ll le[101];

ll JDOE(ll  n, ll  k)
{
    if(!n)
    return 0;
    if(vis[n][k])
    return memo[n][k];
    ll ans = -INF;
    for(ll i=0;i<=k;i++)
    {
        if(i <= le[n])
        ans = std::max(ans, mxd[n][i] + JDOE(n-1, k-i));
    }    
    vis[n][k] = 1;
    memo[n][k] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, 0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    ll n,k;
    std::cin>>n>>k;
    for(ll  i=1;i<=n;i++)
    {
        std::cin>>le[i];
        for(ll  j=1;j<=le[i];j++)
        {
            std::cin>>pref[i][j];
            pref[i][j] += pref[i][j-1];
        }
    }
    for(ll  i=1;i<=n;i++)
    {
        for(ll  j=0;j<=k;j++)
        mxd[i][j] = -INF;
    }
    for(ll  i=1;i<=n;i++)
    {
        for(ll  j=1;j<=le[i];j++)
        {
            for(ll  x=j;x<=std::min(j+k-1, le[i]);x++)
            mxd[i][x-j+1] = std::max(mxd[i][x-j+1], pref[i][x] - pref[i][j-1]);
        }
        mxd[i][0] = 0;
    }
    ll ans = JDOE(n, k);
    std::cout<<ans<<"\n";
    return 0;
}