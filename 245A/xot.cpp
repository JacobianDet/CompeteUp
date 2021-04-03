#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001

std::vector<int> G[CHOR];
std::vector<int> cnt;
int init[CHOR], goal[CHOR], lvl[CHOR];

int dfs_visit(int s, int p, int oz, int ez)
{
    if(p)
    lvl[s] = 1 + lvl[p];
    int z = 0;
    bool t = 0;
    if(lvl[s] & 1)
    {
        t = 1;
        z = oz;
    }
    else z = ez;
    int ans = 0;
    if((init[s] ^ z) != goal[s])
    {
        ans += 1;
        cnt.pb(s);
        z ^= 1;
    }
    for(int i=0,j=(int)G[s].size();i<j;i++)
    {
        if(G[s][i] != p)
        {
            if(t)
            ans += dfs_visit(G[s][i], s, z, ez);
            else ans += dfs_visit(G[s][i], s, oz, z);
        }
    }
    return ans;
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int s,d;
        std::cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
    }
    for(int i=1;i<=n;i++)
    std::cin>>init[i];
    for(int i=1;i<=n;i++)
    std::cin>>goal[i];
    int ans = dfs_visit(1, 0, 0, 0);
    std::cout<<ans<<"\n";
    for(int i=0,j=(int)cnt.size();i<j;i++)
    std::cout<<cnt[i]<<"\n";
    return 0;
}
