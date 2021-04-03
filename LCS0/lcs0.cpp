#include <bits/stdc++.h>

int memo[2][50001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, 0, sizeof(memo));
    std::string s1, s2;
    std::cin>>s1;
    std::cin>>s2;
    int n = (int)s1.size();
    int m = (int)s2.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            memo[1][j] = 1 + memo[0][j-1];
            else
            {
                if(memo[1][j-1] > memo[0][j])
                memo[1][j] = memo[1][j-1];
                else memo[1][j] = memo[0][j];
            }
        }
        for(int j=0;j<=m;j++)
        memo[0][j] = memo[1][j];
    }
    std::cout<<memo[0][m]<<"\n";
    return 0;
}