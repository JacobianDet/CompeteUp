#include <bits/stdc++.h>
#define INF 1000000007

int arr[17][10001], rmin[17][17], rsd[17][17];
int memo[18][18][(1<<16)];
int n;

int MXD(int j, int zu, int mask)
{
    if(mask == ((1<<n)-1))
    return rmin[j][zu];
    if(memo[j][zu][mask] != -1)
    return memo[j][zu][mask];
    int ans = 0;
    if(j == 17)
    {
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(i != k)
                ans = std::max(ans, std::min(rsd[i][k], MXD(i, k, ((mask | (1<<i)) | (1<<k)))));
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!(mask & (1<<i)))
            ans = std::max(ans, std::min(rmin[i][j], MXD(i, zu, mask | (1<<i))));
        }
    } 
    memo[j][zu][mask] = ans;
    return ans;   
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    int m;
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        std::cin>>arr[i][j];
    }
    if(n > 1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rmin[i][j] = INF;
                rsd[i][j] = INF;
            }    
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j)
                {
                    for(int k=0;k<m;k++)
                    rmin[i][j] = std::min(rmin[i][j], abs(arr[i][k] - arr[j][k]));
                    for(int k=0;k<m-1;k++)
                    rsd[i][j] = std::min(rsd[i][j], abs(arr[j][k] - arr[i][k+1]));
                }
            }
        }
        int ans = MXD(17, 17, 0);
        std::cout<<ans<<"\n";
    }
    else
    {
        int ans = INF;
        for(int i=0;i<m-1;i++)
        ans = std::min(ans, abs(arr[0][i] - arr[0][i+1]));
        std::cout<<ans<<"\n";
    }    
    return 0;
}