#include <bits/stdc++.h>
#define pb push_back
#define CHOR 200001

int disc[CHOR], st[CHOR], sze[CHOR];
std::vector<int> G[CHOR];
int tx;

int dfs_visit(int s, int p)
{
    tx++;
    disc[tx] = s;
    st[s] = tx;
    sze[s] = 1;
    for(int i=0,j=(int)G[s].size();i<j;i++)
    {
        if(G[s][i] != p)
        sze[s] += dfs_visit(G[s][i], s);
    }
    return sze[s];
}

int main(void)
{
    int n,q;
    std::cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int p;
        std::cin>>p;
        G[i].pb(p);
        G[p].pb(i);
    }
    tx = 0;
    sze[1] = dfs_visit(1, 0);
    while(q--)
    {
        int u,k;
        std::cin>>u>>k;
        if(k > sze[u])
        std::cout<<"-1\n";
        else
        {
            int v = st[u];
            std::cout<<disc[v+k-1]<<"\n";
        }
    }
    return 0;
}