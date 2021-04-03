#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 1000000000000

typedef long long ll;

std::vector<std::pair<int, ll> > G[10001];
bool vis[10001];
ll key[10001];

ll PrimMST(int n)
{
    for(int i=1;i<=n;i++)
    {
        vis[i] = 0;
        key[i] = INF;
    }
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int> >, std::greater<std::pair<ll, int> > > P;
    P.push(mp(0, 1));
    key[1] = 0;
    ll ans = 0;
    while(!P.empty())
    {
        std::pair<ll, int> p = P.top();
        P.pop();
        int u = p.second;
        if(vis[u])
        continue;
        vis[u] = 1;
        ans += key[u];
        for(int i=0,j=(int)G[u].size();i<j;i++)
        {
            int v = G[u][i].first;
            ll w = G[u][i].second;
            if(!vis[v] && (key[v] > w))
            {
                key[v] = w;
                P.push(mp(key[v], v));
            }
        }
    }
    return ans;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        ll w;
        std::cin>>s>>d>>w;
        G[s].pb(mp(d, w));
        G[d].pb(mp(s, w));
    }
    ll ans = PrimMST(n);
    std::cout<<ans<<"\n";
    return 0;
}
