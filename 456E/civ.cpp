#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

struct xds
{
    int dia, par, sze;
}arr[300001];

std::vector<int> G[300001];
bool vis[300001];

std::pair<int, int> dfs_visit(int s)
{
    vis[s] = 1;
    int g = 0, h1 = 0, h2 = 0;
    for(auto u : G[s])
    {
        if(!vis[u])
        {
            std::pair<int, int> zx = dfs_visit(u);
            g = std::max(g, zx.first);
            if(zx.second > h1)
            {
                h2 = h1;
                h1 = zx.second;
            }
            else if(zx.second <= h1 && zx.second > h2)
            h2 = zx.second;
        }
    }
    g = std::max(g, h1 + h2);
    return mp(g, h1 + 1);
}

class dsu
{
    public: int root(int x);
            void find_union(int x, int y);
};

int dsu::root(int x)
{
    return ((x == arr[x].par) ? x : (arr[x].par = root(arr[x].par)));
}

void dsu::find_union(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)
    return;
    if(arr[rx].sze < arr[ry].sze)
    {
        int tmp = rx;
        rx = ry;
        ry = tmp;
    }
    arr[ry].par = rx;
    arr[rx].sze += arr[ry].sze;
    int d1 = 0, d2 = 0;
    if(arr[rx].dia & 1)
    d1 = (arr[rx].dia)/2 + 1;
    else d1 = (arr[rx].dia)/2;
    if(arr[ry].dia & 1)
    d2 = (arr[ry].dia)/2 + 1;
    else d2 = (arr[ry].dia)/2;
    int dx = d1 + d2 + 1;
    if(dx >= arr[rx].dia && dx >= arr[ry].dia)
    arr[rx].dia = dx;
    else if(arr[ry].dia >= dx && arr[ry].dia >= arr[rx].dia)
    arr[rx].dia = arr[ry].dia;
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m,q;
    std::cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        arr[i].dia = 0;
        arr[i].par = i;
        arr[i].sze = 1;
    }
    dsu T;
    for(int i=0;i<m;i++)
    {
        int s,d;
        std::cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
        T.find_union(s, d);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            std::pair<int, int> zx = dfs_visit(i);
            arr[T.root(i)].dia = zx.first;
        }
    }
    while(q--)
    {
        int t;
        std::cin>>t;
        if(--t)
        {
            int x,y;
            std::cin>>x>>y;
            T.find_union(x, y);
        }
        else
        {
            int x;
            std::cin>>x;
            std::cout<<arr[T.root(x)].dia<<"\n";
        }
    }
    return 0;
}