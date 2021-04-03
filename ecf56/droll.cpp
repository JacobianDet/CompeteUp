#include <bits/stdc++.h>
#define INF 10000000

int memo[101];

int droll(int n)
{
    if(n < 0)
    return INF;
    else if(!n)
    return 0;
    if(memo[n] != -1)
    return memo[n];
    int ans = INF;
    for(int i=2;i<=7;i++)
    ans = std::min(ans, 1 + droll(n-i));
    memo[n] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    for(int i=100;i>1;i--)
    memo[i] = droll(i);
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        std::cout<<memo[n]<<"\n";
    }
    return 0;
}