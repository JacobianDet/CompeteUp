#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 100001

std::vector<int> G[CHOR];
std::vector<int> RG[CHOR];
std::pair<int, int> E[CHOR];
std::vector<int> SCC[CHOR];
std::pair<int, int> finx[CHOR];

bool vis[CHOR];
int cord[CHOR], fin[CHOR];
int tx;

void dfs_vis1(int s)
{
    vis[s] = 1;
    tx++;
    for(int i=0,j=(int)G[s].size();i<j;i++)
    {
        if(!vis[G[s][i]])
        dfs_vis1(G[s][i]);
    }
    tx++;
    fin[s] = tx;
    return;
}

void dfs_vis2(int s, int x)
{
    vis[s] = 1;
    cord[s] = x;
    for(int i=0,j=(int)RG[s].size();i<j;i++)
    {
        if(!vis[RG[s][i]])
        dfs_vis2(RG[s][i], x);
    }
    return;
}



bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    return (a.first > b.first);
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        int f;
        std::cin>>f;
        G[i+1].pb(f);
        RG[f].pb(i+1);
        E[i] = mp(i+1, f);
    }
    tx = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs_vis1(i);
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<n;i++)
    finx[i] = mp(fin[i+1], i+1);
    std::sort(finx, finx+n, cmp);
    int x = 0;
    for(int i=0;i<n;i++)
    {
        int s = finx[i].second;
        if(!vis[s])
        {
            x++;
            dfs_vis2(s, x);
        }
        G[i+1].clear();
    }
    for(int i=1;i<=n;i++)
    SCC[cord[i]].pb(i);
    for(int i=0;i<n;i++)
    {
        int u = E[i].first;
        int v = E[i].second;
        u = cord[u];
        v = cord[v];
        if(u != v)
        G[u].pb(v);
    }
    memset(vis, 0, sizeof(vis));
    memset(fin, 0, sizeof(fin));
    tx = 0;

    return 0;
}
