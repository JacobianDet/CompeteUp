#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 300001
#define INF 10000000000000LL

typedef long long ll;

std::vector<std::pair<int, ll> > G[CHOR];
ll gas[CHOR];

std::pair<ll, ll> dfs_visit(int s, int p)
{
    ll gv = -INF, h1 = -INF, h2 = -INF;
    for(auto u : G[s])
    {
        if(u.first != p)
        {
            std::pair<ll, ll> zx = dfs_visit(u.first, s);
            gv = std::max(gv, zx.first);
            if(h1 < zx.second - u.second)
            {
                h2 = h1;
                h1 = zx.second - u.second;
            }
            else if(h1 > zx.second - u.second && h2 <= zx.second - u.second)
            h2 = zx.second - u.second;
        }
    }
    h1 = std::max(h1, 0LL);
    h2 = std::max(h2, 0LL);
    gv = std::max(gv, h1 + h2 + gas[s]);
    h1 += gas[s];
    return mp(gv, h1);
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>gas[i];
    for(int i=0;i<n-1;i++)
    {
        int s,d;
        ll w;
        std::cin>>s>>d>>w;
        G[s].pb(mp(d, w));
        G[d].pb(mp(s, w));
    }
    std::pair<ll, ll> ans = dfs_visit(1, -1);
    std::cout<<ans.first<<"\n";
    return 0;
}