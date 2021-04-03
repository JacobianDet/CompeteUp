#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

ll memo[10][2002][800];
int cord[10000];
int crx[800];
std::pair<int, int> noz[2001];
int nox[4];
int ctr,n;

void recx(int i, int ld)
{
    if(i == 4)
    {
        int num = 0;
        for(int j=0;j<4;j++)
        num = 10*num + nox[j];
        cord[num] = ctr;
        crx[ctr] = num;
        ctr++;
        return;
    }
    for(int j=0;j<=ld;j++)
    {
        nox[i] = j;
        recx(i+1, j);
    }
    return;
}

ll fcalc(int z, int i, int mask)
{
    if((i == n+1) && (mask == cord[0]))
    return 0;
    if(memo[z][i][mask] != -1)
    return memo[z][i][mask];
    ll ans = 10000000000;
    int nm = 0;
    int d[4], xd[4];
    int x = crx[mask];
    for(int j=0;j<4;j++)
    {
        d[j] = (x%10);
        xd[j] = (x%10);
        x /= 10;
    }
    for(int j=0;j<4;j++)
    {
        if(xd[j])
        {
            d[j] = 0;
            std::sort(d, d+4);
            for(int k=3;k>=0;k--)
            nm = 10*nm + d[k];
            ans = std::min(ans, 1 + abs(xd[j] - z) + fcalc(xd[j], i, cord[nm]));
            for(int k=0;k<4;k++)
            d[k] = xd[k];
            nm = 0;
        }
    }
    if(i < n+1)
    {
        for(int j=0;j<4;j++)
        {
            if(!xd[j])
            {
                d[j] = noz[i].second;
                std::sort(d, d+4);
                for(int k=3;k>=0;k--)
                nm = 10*nm + d[k];
                ans = std::min(ans, 1 + abs(noz[i].first - z) + fcalc(noz[i].first, i+1, cord[nm]));
                for(int k=0;k<4;k++)
                d[k] = xd[k];
                nm = 0;
            }
        }
    }
    memo[z][i][mask] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    ctr = 0;
    recx(0, 9);
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        int s,d;
        std::cin>>s>>d;
        noz[i] = mp(s, d);
    }
    ll ans = fcalc(1, 1, cord[0]);
    std::cout<<ans<<"\n";
    return 0;
}