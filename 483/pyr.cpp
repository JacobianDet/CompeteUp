#include <bits/stdc++.h>

int arr[5001];
int f[5001][5001];
int memo[5001][5001];

int pyrz(int r, int i)
{
    if(r == 1)
    return (f[1][i] = arr[i]);
    if(f[r][i] != -1)
    return f[r][i];
    int ans = pyrz(r-1, i) ^ pyrz(r-1, i+1);
    f[r][i] = ans;
    return ans;
}

int fsmx(int r, int i)
{
    if(r == 1)
    return f[r][i];
    if(memo[r][i] != -1)
    return memo[r][i];
    int ans = std::max(f[r][i], std::max(fsmx(r-1, i), fsmx(r-1, i+1)));
    memo[r][i] = ans;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    memset(f, -1, sizeof(memo));
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    f[n][1] = pyrz(n, 1);
    int q;
    std::cin>>q;
    while(q--)
    {
        int l,r;
        std::cin>>l>>r;
        std::cout<<fsmx(r-l+1, l)<<"\n";
    }
    return 0;
}