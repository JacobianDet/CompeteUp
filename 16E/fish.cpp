#include <bits/stdc++.h>

typedef long double ld;

bool vis[(1<<19)];
ld memo[(1<<19)], arr[19][19];
int n;

ld AYU(int mask)
{
    if(!mask)
    return 1;
    if(vis[mask])
    return memo[mask];
    ld ans = 0;
    ld px = (n - __builtin_popcount(mask) + 1) * (n - __builtin_popcount(mask))/(ld)2;
    for(int i=0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            for(int j=0;j<n;j++)
            {
                if(mask & (1<<j))
                ans += (arr[i][j] * AYU(mask ^ (1<<j)))/px;
            }
        }
    }  
    vis[mask] = 1;
    memo[mask] = ans;
    return ans;
}

int main(void)
{
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%Lf", &arr[i][j]);
    }
    for(int i=0;i<n;i++)
    printf("%Lf ", AYU(((1<<n) - 1) ^ (1<<i)));
    printf("\n");
    return 0;
}