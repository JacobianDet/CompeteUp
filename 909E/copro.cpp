#include <bits/stdc++.h>
#define pb push_back

int cp[100001], indeg[100001], memo[100001];
bool vis[100001];
std::vector<int> G[100001];

int dfs_visit(int s)
{
    if(vis[s])
    return memo[s];
    vis[s] = 1;
    int ans = ((cp[s] == 1) ? 1 : 0);
    for(auto u : G[s])
    {
        if(cp[s])
        {
            if(cp[u])
            ans = std::max(ans, dfs_visit(u));
            else ans = std::max(ans, dfs_visit(u) + 1);
        }
        else ans = std::max(ans, dfs_visit(u));    
    }
    memo[s] = ans;
    return ans;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    std::cin>>cp[i];
    for(int i=0;i<m;i++)
    {
        int s,d;
        std::cin>>s>>d;
        s++;
        d++;
        indeg[d]++;
        G[s].pb(d);
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(!indeg[i])
        ans = std::max(ans, dfs_visit(i));
    }
    std::cout<<ans<<"\n";
    return 0;
}