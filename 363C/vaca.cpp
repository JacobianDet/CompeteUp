#include <bits/stdc++.h>

/*n 0 = REST
    1 = CONTEST
    2 = GYM*/

int arr[101];
int memo[101][4];
int n;

int chedi(int i, int w)
{
    if(i == n+1)
    return 0;
    if(memo[i][w] != -1)
    return memo[i][w];
    int ans = 0;
    if(!arr[i])
    ans = 1 + chedi(i+1, 0);
    else if(arr[i] == 1)
    {
        if(w == 1)
        ans = 1 + chedi(i+1, 0);
        else ans = std::min(chedi(i+1, arr[i]), 1 + chedi(i+1, 0));
    }
    else if(arr[i] == 2)
    {
        if(w == 2)
        ans = 1 + chedi(i+1, 0);
        else ans = std::min(chedi(i+1, arr[i]), 1 + chedi(i+1, 0));
    }
    else
    {
        if(w == 1)
        ans = std::min(chedi(i+1, 2), 1 + chedi(i+1, 0));
        else if(w == 2)
        ans = std::min(chedi(i+1, 1), 1 + chedi(i+1, 0));
        else ans = std::min(std::min(chedi(i+1, 1), chedi(i+1, 2)), 1 + chedi(i+1, 0));
    }
    memo[i][w] = ans;
    return ans;
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    int ans = chedi(1, 3);
    std::cout<<ans<<"\n";
    return 0;
}