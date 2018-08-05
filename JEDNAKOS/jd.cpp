#include <bits/stdc++.h>
#define INF 100000000

int arr[1001];
int memo[1001][5001];
int n;

int plusit(int i, int z)
{
    if(z < 0)
    return INF;
    if(i == n+1)
    {
        if(z != 0)
        return INF;
        else return 0;
    }
    if(memo[i][z] != -1)
    return memo[i][z];
    int ans = INF;
    if(!arr[i])
    ans = plusit(i+1, z);
    else
    {
        int dig = 0;
        int temp = z;
        while(temp)
        {
            dig++;
            temp /= 10;
        }
        for(int j=i;j<i+dig;j++)
        {
            if(j <= n)
            {
                int tx = 0;
                for(int k=i;k<=j;k++)
                tx = 10*tx + arr[k];
                if(j != n)
                ans = std::min(ans, 1 + plusit(j+1, z-tx));
                else ans = std::min(ans, plusit(j+1, z-tx));
            }
        }
    }
    memo[i][z] = ans;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    std::string s;
    std::cin>>s;
    n = -1;
    int z = 0;
    for(int i=0,j=(int)s.size();i<j;i++)
    {
        if(s[i] == '=')
        {
            n = i;
            break;
        }
        arr[i+1] = (s[i] - '0');
    }
    for(int i=n+1,j=(int)s.size();i<j;i++)
    z = 10*z + (s[i] - '0');
    int ans = plusit(1, z);
    std::cout<<ans<<"\n";
    return 0;
}