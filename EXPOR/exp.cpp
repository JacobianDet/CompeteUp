#include <bits/stdc++.h>

typedef unsigned long long ull;

ull ctx[35];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(ctx, 0, sizeof(ctx));
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            std::cin>>x;
            for(int j=0;j<31;j++)
            {
                if(x & (1<<j))
                ctx[j]++;
            }
        }
        ull sum = 0;
        for(int i=0;i<31;i++)
        sum += (1LL*(1LL<<i))*(((1LL*ctx[i])*(ctx[i] - 1))/2 + (1LL*ctx[i])*(n-ctx[i]));
        ull nx = ((1LL*n)*(n-1))/2;
        ull gcx = std::__gcd(sum, nx);
        sum /= gcx;
        nx /= gcx;
        std::cout<<sum<<"/"<<nx<<"\n";
    }
    return 0;
}