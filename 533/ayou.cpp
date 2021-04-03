#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll memo[200001][3];
ll cx[3];

ll fail(int n, int sx)
{
    if(!n)
    {
        if(!sx)
        return 1;
        else return 0;
    }
    if(memo[n][sx] != -1)
    return memo[n][sx];
    ll ans = 0;
    ans = ((((((cx[0]%MOD) * (fail(n-1, sx%3)%MOD))%MOD) + (((cx[1]%MOD) * (fail(n-1, (sx + 1)%3)%MOD))%MOD))%MOD) + (((cx[2]%MOD) * (fail(n-1, (sx + 2)%3)%MOD))%MOD))%MOD;
    memo[n][sx] = ans;
    return ans;    
}

int main(void)
{
    memset(memo, -1, sizeof(memo));
    ll n,l,r;
    std::cin>>n>>l>>r;
    for(int i=0;i<3;i++)
    {
        ll cl = ((l-i+2)/3);
        ll cr = ((r-i+3)/3);
        cx[i] = (cr - cl);
    }
    ll ans = fail(n, 0)%MOD;
    std::cout<<ans<<"\n";
    return 0;
}
