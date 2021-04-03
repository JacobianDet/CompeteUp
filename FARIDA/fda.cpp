#include <bits/stdc++.h>

typedef long long ll;

int n;
ll arr[10001];
ll memo[10001][3];

ll fda(int i, int s)
{
    if(i == n+1)
    return 0;
    if(memo[i][s] != -1)
    return memo[i][s];
    ll ans = 0;
    if(i == 1)
    ans = std::max(fda(i+1, 0), arr[i] + fda(i+1, 1));
    else
    {
        if(!s)
        ans = std::max(fda(i+1, s), arr[i] + fda(i+1, s ^ 1));
        else ans = fda(i+1, s ^ 1);
    }    
    memo[i][s] = ans;
    return ans;
}

int main(void)
{
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(memo, -1, sizeof(memo));
        std::cin>>n;
        for(int i=1;i<=n;i++)
        std::cin>>arr[i];
        ll ans = 0;
        if(n)
        ans = fda(1, 2);
        std::cout<<"Case "<<t<<": "<<ans<<"\n";
    }
    return 0;
}