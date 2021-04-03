#include <bits/stdc++.h>
#define CHOR 5001
#define pb push_back
#define mp std::make_pair

std::vector<int> G[CHOR];
std::vector<int> RG[CHOR];
std::pair<int, int> E[CHOR+1];
std::pair<int, int> finx[CHOR];

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

int main(void)
{
    int n,m,z;
    std::cin>>n>>m>>z;
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
    z = cord[z];
    for(int i=0;i<m;i++)
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
    int ct = 0;
    for(int i=1;i<=x;i++)
    {
        if(!vis[i])
        {    
            dfs_vis1(i);
            ct++;
            if(i == z)
            ct--;
        }        
    }    
    std::cout<<ct<<"\n";
    return 0;    
}