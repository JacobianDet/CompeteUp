#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 100011
#define AMMA 10007

std::vector<int> G[CHOR];
std::pair<int, int> memo[CHOR][3];
int vis[CHOR][3];

std::pair<int, int> dfs_visit(int s, int p, int x, int t)
{
    int j = (int)G[s].size();
    if(j == 1 && G[s][j-1] == p)
    {
        if(x)
        return mp(0, 1);
        else return mp(1, 1);
    }
    if(vis[s][x] == t)
    return memo[s][x];
    int a0 = 0, a1 = 1, w0 = 1, w1 = 1;
    int ans1 = 0, ans2 = 1;
    for(int i=0;i<j;i++)
    {
        if(G[s][i] != p)
        {
            if(x == 2 || x == 1)
            {
                std::pair<int, int> p = dfs_visit(G[s][i], s, 1, t);
                a1 += p.first;
                w1 = ((w1%AMMA) * ((p.second)%AMMA))%AMMA;
                p = dfs_visit(G[s][i], s, 0, t);
                a0 += p.first;
                w0 = ((w0%AMMA) * ((p.second)%AMMA))%AMMA;
            }
            else 
            {
                std::pair<int, int> p = dfs_visit(G[s][i], s, 1, t);
                a1 += p.first;
                w1 = ((w1%AMMA) * ((p.second)%AMMA))%AMMA;
            }    
        }
    }
    if(x)
    {
        if(a1 < a0)
        {
           ans1 = a1;
           ans2 = w1;
        }
        else if(a0 < a1)
        {
            ans1 = a0;
            ans2 = w0;
        }
        else
        {
            ans1 = a0;
            ans2 = ((w0%AMMA) + (w1%AMMA))%AMMA;
        }
    }
    else
    {
        ans1 = a1;
        ans2 = w1;
    }
    vis[s][x] = t;
    memo[s][x] = mp(ans1, ans2);
    return mp(ans1, ans2);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    memset(vis, 0, sizeof(vis));
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        for(int i=0;i<CHOR;i++)
        G[i].clear();
        int n;
        std::cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int s,d;
            std::cin>>s>>d;
            G[s].pb(d);
            G[d].pb(s);
        }
        std::pair<int, int> p = dfs_visit(1, 0, 2, t);
        std::cout<<p.first<<" "<<p.second<<"\n";
    }    
    return 0;
}