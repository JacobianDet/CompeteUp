#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001

std::vector<int> G[CHOR];
int vis[CHOR];

bool dfs_visit(int s, int p)
{
    if(p != 0)
    {
        if(vis[p] == 1)
        vis[s] = 2;
        else vis[s] = 1;
    }
    else vis[s] = 1;
    bool ok = 1;
    for(int i=0,j=(int)G[s].size();i<j;i++)
    {
        if(!vis[G[s][i]])
        ok &= dfs_visit(G[s][i], s);
        else if(vis[G[s][i]] == vis[s])
        ok = 0;
    }
    return ok;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        std::cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
    }
    bool ok = 1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        ok &= dfs_visit(i, 0);
        if(!ok)
        break;
    }    
    if(ok)
    {
        std::vector<int> L1;
        std::vector<int> L2;
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == 1)
            L1.pb(i);
            else L2.pb(i);
        }
        std::cout<<(int)L1.size()<<"\n";
        for(int i=0,j=(int)L1.size();i<j;i++)
        std::cout<<L1[i]<<" ";
        std::cout<<"\n";
        std::cout<<(int)L2.size()<<"\n";
        for(int i=0,j=(int)L2.size();i<j;i++)
        std::cout<<L2[i]<<" ";
        std::cout<<"\n";
    }
    else std::cout<<"-1\n";
    return 0;
}
