#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

ll arr[200001], inx[200001], sx[200001];
std::vector<int> G[200001];

std::pair<ll, ll> dfs_vis1(int s, int p)
{
    for(auto u : G[s])
    {
        if(u != p)
        {
            std::pair<ll, ll> vx = dfs_vis1(u, s);
            sx[s] += (vx.first + vx.second);
            inx[s] += vx.first;
        }
    }
    inx[s] += arr[s];
    return mp(inx[s], sx[s]);
}

ll dfs_vis2(int s, int p, ll ix, ll vx)
{
    ll ax = vx + ix, ans = 0;
    for(auto u : G[s])
    {
        if(u != p)
        ax += (inx[u] + sx[u]);
    }
    ans = std::max(ans, ax);
    for(auto u : G[s])
    {
        if(u != p)
        ans = std::max(ans, dfs_vis2(u, s, ix+inx[s]-inx[u], ax-inx[u]-sx[u]));
    }
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    for(int i=0;i<n-1;i++)
    {
        int s,d;
        std::cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
    }
    std::pair<ll, ll> vx = dfs_vis1(1, -1);
    ll ans = dfs_vis2(1, -1, 0, 0);
    std::cout<<ans<<"\n";
    return 0;
}