#include <bits/stdc++.h>

int m, c0, d0;

struct xyj
{
    int a, b, c, d;
}arr[11];

int memo[11][1001];

int dfx(int i, int n)
{
    if(i == m+1)
    {
        if(n >= c0)
        return (d0 * (n/c0));
        else return 0;
    }
    if(memo[i][n] != -1)
    return memo[i][n];
    int ans = 0;
    if((arr[i].a >= arr[i].b) && (n >= arr[i].c))
    {
        for(int j=0;j<=std::min((arr[i].a/arr[i].b), (n/arr[i].c));j++)
        ans = std::max(ans, j*arr[i].d + dfx(i+1, n-j*arr[i].c));
    }
    else ans = dfx(i+1, n);
    memo[i][n] = ans;
    return ans;    
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n;
    std::cin>>n>>m>>c0>>d0;
    for(int i=1;i<=m;i++)
    std::cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;
    int ans = dfx(1, n);
    std::cout<<ans<<"\n";
    return 0;
}