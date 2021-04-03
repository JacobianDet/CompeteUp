#include <bits/stdc++.h>

std::string s;
int memo[2001][4001];
int vis[2001][4001];

int bax(int n, int bf, int t)
{
    if(!n)
    {
        if(bf != 2000)
        return 1000000;
        else return 0;
    }
    if(vis[n][bf] == t)
    return memo[n][bf];
    int obf = bf - 2000;
    int ans = 0;
    if(!obf)
    {
        if(s[n-1] == '}')
        ans = bax(n-1, obf - 1 + 2000, t);
        else ans = 1 + bax(n-1, obf - 1 + 2000, t);
    }
    else if(obf > 0)
    {
        if(s[n-1] == '}')
        ans = bax(n-1, bf, t);
        else ans = bax(n-1, bf, t);
    }
    else
    {
        if(s[n-1] == '}')
        ans = std::min(1 + bax(n-1, obf + 1 + 2000, t), bax(n-1, obf - 1 + 2000, t));
        else ans = bax(n-1, obf + 1 + 2000, t);
    }
    vis[n][bf] = t;
    memo[n][bf] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(vis, 0, sizeof(vis));
    int t = 1;
    std::cin>>s;
    while(s[0] != '-')
    {
        int n = (int)s.size();
        int ans = bax(n, 2000, t);
        std::cout<<t<<". "<<ans<<"\n";
        std::cin>>s;
        t++;
    }
    return 0;
}
