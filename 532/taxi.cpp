#include <bits/stdc++.h>
#define pb push_back

struct t3
{
    int s,d,w;
}E[100001];

std::vector<int> G[100001];
int vis[100001], tx[100001];
std::vector<int> finx;

bool dfs_vis1(int s)
{
    vis[s] = 1;
    bool ok = 1;
    for(auto u : G[s])
    {
        if(!vis[u])
        ok &= dfs_vis1(u);
        else if(vis[u] == 1)
        ok = 0;
    }
    vis[s] = 2;
    return ok;
}

void dfs_vis2(int s)
{
    vis[s] = 1;
    for(auto u : G[s])
    {
        if(!vis[u])
        dfs_vis2(u);
    }
    finx.pb(s);
    return;
}

int bs1(int n, int m)
{
    int mw = 0;
    for(int i=0;i<m;i++)
    mw = std::max(mw, E[i].w);
    int lo = 0;
    int hi = mw;
    while(lo < hi)
    {
        int mid = lo + (hi - lo)/2;
        for(int i=0;i<m;i++)
        {
            if(E[i].w > mid)
            G[E[i].s].pb(E[i].d);
        }
        bool ok = 1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            ok &= dfs_vis1(i);
        }  
        if(ok)
        hi = mid;
        else lo = mid + 1;
        for(int i=1;i<=n;i++)
        {
            vis[i] = 0;
            G[i].clear();
        }   
    }
    return lo;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    std::cin>>E[i].s>>E[i].d>>E[i].w;
    int ans = bs1(n, m);
    for(int i=0;i<m;i++)
    {
        if(E[i].w > ans)
        G[E[i].s].pb(E[i].d);
    }
    std::vector<int> ix;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs_vis2(i);
    }
    std::reverse(finx.begin(), finx.end());
    int tm = 0;
    for(int i=0;i<n;i++)
    tx[finx[i]] = (++tm);
    for(int i=0;i<m;i++)
    {
        if(E[i].w <= ans)
        {
            if(tx[E[i].s] > tx[E[i].d])
            ix.pb(i+1);
        }
    }
    std::cout<<ans<<" "<<(int)ix.size()<<"\n";
    for(int i=0,j=(int)ix.size();i<j;i++)
    std::cout<<ix[i]<<" ";
    std::cout<<"\n";
    return 0;
}