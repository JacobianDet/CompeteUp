#include <bits/stdc++.h>

void dfs_visit(int s, std::vector<std::vector<int>> &G, std::vector<bool> &vis)
{
    vis[s] = true;
    for(int i=0,j=G[s].size();i<j;i++)
    {
        if(vis[G[s][i]] == false)
        dfs_visit(G[s][i], G, vis);
    }
    return;
}

int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    std::vector<std::vector<int>> G(n+1);
    int s,d,c=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&s,&d);
        G[s].push_back(d);
        G[d].push_back(s);
    }
    std::vector<bool> vis(n+1);
    for(int i=1;i<=n;i++)
    {
       if(vis[i] == false)
       {
            dfs_visit(i,G,vis);
            c++;
       }
    }
    if(m == n-1 && c == 1)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}
