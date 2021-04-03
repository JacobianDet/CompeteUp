#include <bits/stdc++.h>

//SOURCE CODE BY anuragsingh804

typedef long long ll;

std::string s;
ll arr[101], memo[101][101][101];

ll fun(int i, int j, int c)
{
    if(i > j)
    return 0;
    else if(i == j)
    return arr[c+1];
    if(memo[i][j][c] != -1)
    return memo[i][j][c];
    ll ans = 0;
    for(int k=i+1;k<=j;k++)
    {
        if(s[i-1] == s[k-1])
        ans = std::max(ans, fun(i+1, k-1, 0) + fun(k, j, c+1));
    }
    ans = std::max(ans, arr[c+1] + fun(i+1, j, 0));
    memo[i][j][c] = ans;
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
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    ll ans = fun(1, n, 0);
    std::cout<<ans<<"\n";
    return 0;
}