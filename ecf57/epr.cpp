#include <bits/stdc++.h>
#define pb push_back
#define INF 1000000000000000

typedef long long ll;

ll arr[100001];
ll memo[4][100001];
std::map<int, char> mci;
int fx[4][2];
std::vector<int> lx[4];

ll HIMANSHU(int i, int p)
{
    if(p == (int)lx[i].size())
    return 0;
    if(memo[i][p] != -1)
    return memo[i][p];
    ll ans = INF;
    ans = std::min(ans, arr[lx[i][p]] + HIMANSHU(i, p+1));
    if(i < 3)
    {
        int px = std::upper_bound(lx[i+1].begin(), lx[i+1].end(), lx[i][p]) - lx[i+1].begin();
        ans = std::min(ans, HIMANSHU(i+1, px));
    }
    memo[i][p] = ans;
    return ans;    
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    memset(fx, -1, sizeof(fx));
    mci[0] = 'h';
    mci[1] = 'a';
    mci[2] = 'r';
    mci[3] = 'd';
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j] == mci[i])
            {
                fx[i][0] = j;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(s[j] == mci[i])
            {
                fx[i][1] = j;
                break;
            }
        }
    }
    for(int i=3;i>=0;i--)
    {
        if(i < 3)
        fx[i][1] = std::min(fx[i][1], fx[i+1][1]);
    }
    for(int i=0;i<4;i++)
    {
        if(i)
        fx[i][0] = std::min(fx[i][0], fx[i-1][0]);
    }
    bool ok = 1;
    for(int i=0;i<4;i++)
    {
        if((fx[i][0] > fx[i][1]) && ((fx[i][0] == fx[i][1]) && (fx[i][0] == -1)))
        {
            ok = 0;
            break;
        }
    }
    if(!ok)
    std::cout<<"0\n";
    else
    {
        for(int i=0;i<4;i++)
        {
            for(int j=fx[i][0];j<=fx[i][1];j++)
            {
                if(s[j] == mci[i])
                lx[i].pb(j+1);
            }
        }
        ll ans = HIMANSHU(0, 0);
        std::cout<<ans<<"\n";
    }
    return 0;
}