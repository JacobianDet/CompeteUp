#include <bits/stdc++.h>
#define mp std::make_pair
#define INF 1000000000000000

typedef long long ll;

int n;
std::pair<int, ll> arr[2001];
ll memo[2001][4004];

ll oxkn(int i, int t)
{
    if(i == n+1)
    {
        if(t < 2000)
        return INF;
        else if(t >= 2000)
        return 0;
    }
    if(memo[i][t] != -1)
    return memo[i][t];
    ll ans = 0;
    int wt = t - 2000;
    ans = std::min(arr[i].second + oxkn(i+1, 2000 + std::min(wt + arr[i].first, n)), oxkn(i+1, t-1));
    memo[i][t] = ans;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        ll c;
        std::cin>>t>>c;
        arr[i] = mp(t, c);
    }
    ll ans = oxkn(1, 2000);
    std::cout<<ans<<"\n";
    return 0;
}
