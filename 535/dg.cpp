#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 100000001

/* R = 0
    G = 1
    B = 2*/

std::string s;
int memo[200001][4];
std::pair<int, int> par[200001][4];

int RAX(int n, int c)
{
    if(!n)
    return 0;
    if(memo[n][c] != -1)
    return memo[n][c];
    int ans = INF;
    for(int i=0;i<3;i++)
    {
        if(c != i)
        {
            int tw = 0;
            if(((s[n-1] == 'R') && (i != 0)) || ((s[n-1] == 'G') && (i != 1)) || ((s[n-1] == 'B') && (i != 2)))
            tw = 1;
            if(ans > tw + RAX(n-1, i))
            {
                ans = tw + RAX(n-1, i);
                par[n][c] = mp(n-1, i);
            }
        }
    }
    memo[n][c] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n;
    std::cin>>n>>s;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        par[i][j] = mp(i, j);
    }
    int ans = RAX(n, 3);
    int s1 = n, s2 = 3;
    while(s1)
    {
        int ns1 = par[s1][s2].first;
        int ns2 = par[s1][s2].second;
        if(ns2 == 0)
        s[ns1] = 'R';
        else if(ns2 == 1)
        s[ns1] = 'G';
        else s[ns1] = 'B';
        s1 = ns1;
        s2 = ns2;
    }
    std::cout<<ans<<"\n"<<s<<"\n";
    return 0;
}