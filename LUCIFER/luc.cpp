#include <bits/stdc++.h>

int A[11], B[11];
bool isP[100001];
int memo[11][50][50][(1<<2)];

void siever(void)
{
    memset(isP, 1, sizeof(isP));
    isP[0] = 0;
    isP[1] = 0;
    for(int p=2;p*p<100001;p++)
    {
        if(isP[p])
        {
            for(int i=p*p;i<100001;i+=p)
            isP[i] = 0;
        }    
    }
    return;
}

int digdp(int i, int x, int y, int mask)
{
    if(i == 11)
    {
        if(((y-x) > 0) && isP[(y-x)])
        return 1;
        else return 0;
    }
    if(memo[i][x][y][mask] != -1)
    return memo[i][x][y][mask];
    int ans = 0;
    if(!mask)
    {
        for(int j=A[i];j<=B[i];j++)
        {
            if((j > A[i]) && (j < B[i]))
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, 3);
                else ans += digdp(i+1, x, y+j, 3); 
            }
            else if(j > A[i])
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, 2);
                else ans += digdp(i+1, x, y+j, 2); 
            }    
            else if(j < B[i])
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, 1);
                else ans += digdp(i+1, x, y+j, 1);   
            }
            else 
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, mask);
                else ans += digdp(i+1, x, y+j, mask);   
            }
        }
    }
    else if(mask == 1)
    {
        for(int j=A[i];j<=9;j++)
        {
            if(j > A[i])
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, 3);
                else ans += digdp(i+1, x, y+j, 3);    
            }
            else
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, mask);
                else ans += digdp(i+1, x, y+j, mask);
            }
        }
    }
    else if(mask == 2)
    {
        for(int j=0;j<=B[i];j++)
        {
            if(j < B[i])
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, 3);
                else ans += digdp(i+1, x, y+j, 3);
            }
            else
            {
                if(!(i & 1))
                ans += digdp(i+1, x+j, y, mask);
                else ans += digdp(i+1, x, y+j, mask);
            }
        }
    }
    else
    {
        for(int j=0;j<=9;j++)
        {
            if(!(i & 1))
            ans += digdp(i+1, x+j, y, mask);
            else ans += digdp(i+1, x, y+j, mask);
        }
    }
    memo[i][x][y][mask] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    siever();
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(memo, -1, sizeof(memo));
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        int a, b;
        std::cin>>a>>b;
        int x = 10;
        int temp = a;
        while(temp)
        {
            A[x--] = (temp%10);
            temp /= 10;
        }
        x = 10;
        temp = b;
        while(temp)
        {
            B[x--] = (temp%10);
            temp /= 10;
        }
        int ans = digdp(1, 0, 0, 0);
        std::cout<<ans<<"\n";
    }
    return 0;
}