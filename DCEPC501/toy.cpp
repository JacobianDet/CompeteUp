#include <bits/stdc++.h>

typedef long long ll;

int n;
ll arr[100001];
ll memo[100001];

ll toy(int i)
{
    if(i > n)
    return 0;
    if(memo[i] != -1)
    return memo[i];
    ll ans = 0;
    for(int j=0;j<3;j++)
    {
        if(i+j <= n)
        ans = std::max(ans, (arr[i+j] - arr[i-1]) + toy(i+2*(j+1)));
    }
    memo[i] = ans;
    return memo[i];    
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(memo, -1, sizeof(memo));
        memset(arr, 0, sizeof(arr));
        std::cin>>n;
        for(int i=1;i<=n;i++)
        {
            std::cin>>arr[i];
            arr[i] += arr[i-1];
        }
        ll ans = toy(1);
        std::cout<<ans<<"\n";
    }
    return 0;
}