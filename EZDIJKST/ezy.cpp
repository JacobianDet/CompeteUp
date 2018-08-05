#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 10001

typedef long long ll;

std::vector<std::pair<int, ll> > G[CHOR];
bool vis[CHOR];
ll dist[CHOR];

void dijkstra_find(int a)
{
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int> >, std::greater<std::pair<ll, int> > > P;
    dist[a] = 0;
    P.push(mp(0, a));
    while(!P.empty())
    {
        std::pair<int, int> p = P.top();
        P.pop();
        int u = p.second;
        if(vis[u])
        continue;
        vis[u] = 1;
        for(int i=0,j=(int)G[u].size();i<j;i++)
        {
            int v = G[u][i].first;
            ll w = G[u][i].second;
            if(!vis[v] && (dist[v] > dist[u] + w))
            {
                dist[v] = dist[u] + w;
                P.push(mp(dist[v], v));
            }
        }
    }
    return;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,m;
        std::cin>>n>>m;
        for(int i=0;i<CHOR;i++)
        {
            vis[i] = 0;
            dist[i] = 1000000000000;
            G[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int s,d;
            ll w;
            std::cin>>s>>d>>w;
            G[s].pb(mp(d, w));
        }
        int a,b;
        std::cin>>a>>b;
        dijkstra_find(a);
        if(dist[b] != 1000000000000)
        std::cout<<dist[b]<<"\n";
        else std::cout<<"NO\n";
    }
    return 0;
}