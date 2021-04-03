#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define graph std::vector<std::vector<ll> >

int cyc = 0;

void bfs_visit(graph &G, std::vector<ll> &tsort, std::vector<ll> &indeg)
{
        std::priority_queue<ll, std::vector<ll>, std::greater<ll> > pq;
        ll n = indeg.size();
        for(ll i=1;i<n;i++)
        {
            if(!indeg[i])
            pq.push(i);
        }
        while(!pq.empty())
        {
            ll t = pq.top();
            pq.pop();
            tsort.pb(t);
            for(ll i=0,j=G[t].size();i<j;i++)
            {
                indeg[G[t][i]]--;
                if(!indeg[G[t][i]])
                pq.push(G[t][i]);
            }
        }
        for(ll i=1;i<n;i++)
        {
            if(indeg[i])
            cyc = 1;
        }
        return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ll n,m,x,y;
    std::cin>>n>>m;
    graph G(n+1);
    for(ll i=0;i<m;i++)
    {
        std::cin>>x>>y;
        G[x].pb(y);
    }
    std::vector<ll> tsort;
    std::vector<ll> indeg(n+1);
    for(ll i=1;i<n+1;i++)
    {
        for(std::vector<ll>::iterator it = G[i].begin(); it != G[i].end(); it++)
        indeg[(*it)]++;
    }
    bfs_visit(G, tsort, indeg);
    if(cyc & 1)
    {
        std::cout<<"Sandro fails.\n";
        return 0;
    }
    for(std::vector<ll>::iterator it = tsort.begin(); it != tsort.end(); it++)
    std::cout<<*it<<" ";
    std::cout<<"\n";
    return 0;
}
