#include <bits/stdc++.h>
#define MOD 998244353
#define CHOR 300001
#define pb push_back

typedef long long ll;

ll modexp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%MOD) * (a%MOD))%MOD;
        a = ((a%MOD) * (a%MOD))%MOD;
        n >>= 1;
    }
    return res;
}

std::vector<int> G[CHOR];
int col[CHOR];

struct czx
{
    bool ok;
    ll ct1, ct2;
};

czx dfs_visit(int s)
{
    ll cl1 = 0, cl2 = 0;
    bool ok = 0;
    for(auto u : G[s])
    {
        if(!col[u])
        {
            if(col[s] == 1)
            {
                col[u] = 2;
                czx yt = dfs_visit(u);
                cl1 += yt.ct1;
                cl2 += yt.ct2;
                ok |= yt.ok;
            }
            else
            {
                col[u] = 1;
                czx yt = dfs_visit(u);
                cl1 += yt.ct1;
                cl2 += yt.ct2;
                ok |= yt.ok; 
            }    
        }
        else if(col[u] == col[s])
        ok = 1;
    }
    if(col[s] == 1)
    cl1++;
    else cl2++;
    if(ok)
    return {ok, 0, 0};
    else return {ok, cl1, cl2};
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
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
        ll ans = 1;
        for(int i=1;i<=n;i++)
        {
            if(!col[i])
            {
                col[i] = 1;
                czx yt = dfs_visit(i);
                if(yt.ok)
                {
                    ans = 0;
                    break;
                }
                else ans = (((ans%MOD) * (((modexp(2, yt.ct1)%MOD) + (modexp(2, yt.ct2)%MOD))%MOD))%MOD);
            }
        }
        std::cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            col[i] = 0;
            G[i].clear();
        }
    }
    return 0;
}