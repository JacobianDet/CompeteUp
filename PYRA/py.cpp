#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 10001

std::vector<int> G[CHOR];

std::pair<int, int> dfs_visit(int s, int p)
{
    int cv = 0, ans = 0;
    for(int i=0,j=(int)G[s].size();i<j;i++)
    {
        if(G[s][i] != p)
        {
            std::pair<int, int> rx = dfs_visit(G[s][i], s);
            cv += (rx.second + 1);
            ans += rx.first;
        }
    }
    ans += (cv + 1);
    return mp(ans, cv + 1);
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=1;i<=n;i++)
        G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int s,d;
            std::cin>>s>>d;
            s++;
            d++;
            G[s].pb(d);
            G[d].pb(s);
        }
        int ans = dfs_visit(1, 0).first;
        std::cout<<ans<<"\n";
    }
    return 0;
}
