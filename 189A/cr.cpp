#include <bits/stdc++.h>

int a,b,c;
int memo[4001];
bool vis[4001];

int rib(int n)
{
    if((n < 0) || ((n > 0) && (n < a) && (n < b) && (n < c)))
    return -5000;
    else if(!n)
    return 0;
    if(vis[n])
    return memo[n];
    int ans = -5000;
    ans = 1 + std::max(rib(n-a), std::max(rib(n-b), rib(n-c)));
    memo[n] = ans;
    vis[n] = 1;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    int n;
    std::cin>>n>>a>>b>>c;
    int ans = rib(n);
    std::cout<<ans<<"\n";
    return 0;
}