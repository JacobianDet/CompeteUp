#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back
#define mp std::make_pair

std::vector<int> G[CHOR];
std::vector<int> RG[CHOR];
std::pair<int, int> E[(CHOR << 1)];
std::pair<int, int> finx[CHOR];
std::vector<int> SCC[CHOR];

bool vis[CHOR];
int fin[CHOR], cord[CHOR];
int tx;

bool comp(std::pair<int, int> a, std::pair<int, int> b)
{
    return (a.first > b.first);
}

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

std::vector<int> merger(std::vector<int> a1, std::vector<int> a2)
{
    std::vector<int> res;
    int n1 = (int)a1.size(), n2 = (int)a2.size();
    int i=0,j=0;
    while(i != n1 && j != n2)
    {
        if(a1[i] < a2[j])
        {
            res.pb(a1[i]);
            i++;
        }
        else
        {
            res.pb(a2[j]);
            j++;
        }    
    }
    while(i != n1)
    {
        res.pb(a1[i]);
        i++;
    }   
    while(j != n2)
    {
        res.pb(a2[j]);
        j++;
    } 
    return res;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        std::cin>>u>>v;
        G[u].pb(v);
        RG[v].pb(u);
        E[i] = mp(u, v);
    }    
    tx = 0;
    memset(vis, 0, sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs_vis1(i);        
    }  
    for(int i=1;i<=n;i++)
    finx[i] = mp(fin[i], i);
    std::sort(finx+1, finx+n+1, comp);
    memset(vis, 0, sizeof(vis));
    int x = 0;
    for(int i=1;i<=n;i++)
    {
        int s = finx[i].second;
        if(!vis[s])
        {   
            x++; 
            dfs_vis2(s, x);
        }
        G[i].clear();        
    }
    for(int i=1;i<=n;i++)
    SCC[cord[i]].pb(i);
    for(int i=0;i<m;i++)
    {
        int u = E[i].first;
        int v = E[i].second;
        u = cord[u];
        v = cord[v];
        if(u != v)
        G[u].pb(v);
    } 
    std::vector<int> res;
    for(int i=1;i<=x;i++)
    {
        if((int)G[i].size() == 0)
        res = merger(res, SCC[i]);    
    }   
    std::cout<<(int)res.size()<<"\n";
    for(int i=0,j=(int)res.size();i<j;i++)
    std::cout<<res[i]<<" ";
    std::cout<<"\n";
    return 0; 
}