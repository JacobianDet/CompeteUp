#include <bits/stdc++.h>

int memo[901][8101], digx[901][8101];

/*int timus(int sd, int sq)
{
    if(!sd && !sq)
    return 0;
    else if((sd <= 0) || (sq <= 0) || (vis[sd][sq] == 1))
    return 1000000;
    if(vis[sd][sq] == 2)
    return memo[sd][sq];
    vis[sd][sq] = 1;
    int ans = 1000000;
    for(int i=0;i<=9;i++)
    {
        if(ans > 1 + timus(sd-i, sq-i*i))
        {
            ans = std::min(ans, 1 + timus(sd-i, sq-(i*i)));
            digx[sd][sq] = i;
            par[sd][sq] = mp(sd-i, sq-i*i);
        }
    }
    vis[sd][sq] = 2;
    memo[sd][sq] = ans;
    return ans;
}*/

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    for(int i=0;i<=900;i++)
    {
        for(int j=0;j<=8100;j++)
        {
            memo[i][j] = 1000000;
            digx[i][j] = 0;
        }
    }
    memo[0][0] = 0;
    for(int i=1;i<=8100;i++)
    memo[0][i] = 1000000;
    for(int i=1;i<=900;i++)
    memo[i][0] = 1000000;
    for(int i=1;i<=900;i++)
    {
        for(int j=1;j<=8100;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(((i-k) >= 0) && ((j-k*k) >= 0) && (memo[i][j] > (1 + memo[i-k][j-k*k])))
                {
                    memo[i][j] = 1 + memo[i-k][j-k*k];
                    digx[i][j] = k;
                }
            }
        }
    }
    int T;
    std::cin>>T;
    while(T--)
    {
        int sd = 0, sq = 0;
        std::cin>>sd>>sq;
        if((sd > 900) || (sq > 8100) || (memo[sd][sq] > 100))
        std::cout<<"No solution\n";
        else
        {
            int psd = sd, psq = sq, dig = -1;
            while(psd && psq)
            {
               dig = digx[psd][psq];
               std::cout<<dig;
               psd -= dig;
               psq -= (dig * dig);
            }
            std::cout<<"\n";
        }
    }
    return 0;
}
