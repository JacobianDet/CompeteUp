#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll ctz[2001], factx[100001], invf[100001];
ll memo[2001][2001];
std::map<int, int> lct;
int zx, px;

ll modexp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%MOD) * (a%MOD))%MOD;
        a = ((a%MOD) * (a%MOD))%MOD;
        n >>= 1;
    }
    return res;
}

void factup(void)
{
    factx[0] = 1;
    invf[0] = 1;
    for(ll i=1;i<100001;i++)
    {
        factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
        invf[i] = modexp(factx[i], MOD-2)%MOD;
    }
    return;
}

ll ZXF(int i, int cx)
{
    if(cx < 0)
    return 0;
    else if(i == px + 1)
    {
        if(zx < cx)
        return 0;
        else return (((((factx[zx]%MOD) * (invf[cx]%MOD))%MOD) * (invf[zx-cx]%MOD))%MOD);
    }
    if(memo[i][cx] != -1)
    return memo[i][cx];
    ll ans = 0;
    ans = ((ZXF(i+1, cx)%MOD) + (((ctz[i]%MOD) * (ZXF(i+1, cx-1)%MOD))%MOD))%MOD;
    memo[i][cx] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    factup();
    memset(memo, -1, sizeof(memo));
    int n,k;
    std::cin>>n>>k;
    zx = 0, px = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x; 
        int t = x, c4 = 0, c7 = 0, td = 0;
        while(t)
        {
            if((t % 10) == 4)
            c4++;
            else if((t % 10) == 7)
            c7++;
            t /= 10;
            td++;
        }
        if(c4 + c7 == td)
        {
            if(!lct[x])
            {
                px++;
                lct[x] = px;
                ctz[px]++;
            }
            else ctz[lct[x]]++;
        }
        else zx++;
    }
    ll ans = ZXF(1, k)%MOD;
    std::cout<<ans<<"\n";
    return 0;
}