#include <bits/stdc++.h>

typedef long long ll;

int A[17], B[17];
ll memo[17][150][(1<<2)];

ll dsumx(int i, int sx, int mask)
{
    if(i == 17)
    return 1LL*sx;
    if(memo[i][sx][mask] != -1)
    return memo[i][sx][mask];
    ll ans = 0;
    if(!mask)
    {
        for(int j=A[i];j<=B[i];j++)
        {
            if(j > A[i] && j < B[i])
            ans += dsumx(i+1, sx+j, 3);
            else if(j > A[i])
            ans += dsumx(i+1, sx+j, 2);
            else if(j < B[i])
            ans += dsumx(i+1, sx+j, 1);
            else ans += dsumx(i+1, sx+j, mask);
        }
    }
    else if(mask == 1)
    {
        for(int j=A[i];j<=9;j++)
        {
            if(j > A[i])
            ans += dsumx(i+1, sx+j, 3);
            else ans += dsumx(i+1, sx+j, mask);
        }
    } 
    else if(mask == 2)
    {
        for(int j=0;j<=B[i];j++)
        {
            if(j < B[i])
            ans += dsumx(i+1, sx+j, 3);
            else ans += dsumx(i+1, sx+j, mask);
        }
    }
    else
    {
        for(int j=0;j<=9;j++)
        ans += dsumx(i+1, sx+j, mask);
    }
    memo[i][sx][mask] = ans;
    return ans;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(memo, -1, sizeof(memo));
        ll a,b;
        std::cin>>a>>b;
        int x = 16;
        ll temp = a;
        while(temp)
        {
            A[x--] = (temp%10);
            temp /= 10;
        }
        x = 16;
        temp = b;
        while(temp)
        {
            B[x--] = (temp%10);
            temp /= 10;
        }
        ll ans = dsumx(1, 0, 0);
        std::cout<<ans<<"\n";
    }
    return 0;
}