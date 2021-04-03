#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001

int cnt[CHOR], h[11];
std::vector<int> Z;
std::vector<int> f[CHOR];
int memo[501][5001];
int k;

int colmov(int col, int n, int x)
{
    if(n == (int)f[col].size())
    return 0;
    if(memo[n][x] != -1)
    return memo[n][x];
    int ans = 0;
    for(int i=0;i<=std::min(k, cnt[col]-x);i++)
    ans = std::max(ans, h[i]+colmov(col, n+1, x+i));
    memo[n][x] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n;
    std::cin>>n>>k;
    for(int i=0;i<k*n;i++)
    {
        int t;
        std::cin>>t;
        if(!cnt[t])
        {
            Z.pb(t);
            cnt[t]++;
        }
        else cnt[t]++;
    }
    for(int i=0;i<n;i++)
    {
        int t;
        std::cin>>t;
        int sz = (int)f[t].size();
        f[t].pb(sz);
    }
    for(int i=1;i<=k;i++)
    std::cin>>h[i];
    int ans = 0;
    for(int i=0,j=(int)Z.size();i<j;i++)
    {
        if((int)f[Z[i]].size() == 0)
        continue;
        else if((int)f[Z[i]].size() == 1)
        {
            if(cnt[Z[i]] >= k)
            ans += h[k];
            else ans += h[cnt[Z[i]]];
        }
        else
        {
            memset(memo, -1, sizeof(memo));
            ans += colmov(Z[i], 0, 0);
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}
