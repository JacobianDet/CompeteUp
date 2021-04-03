#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
 
typedef long long ll;
 
std::vector<std::vector<ll> > vx;
std::vector<std::vector<std::pair<ll, ll> > > pz;
std::vector<ll> noz;
std::vector<std::vector<ll> > memo;
ll n;

ll readInt (void) {
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
 
int main(void)
{
    ll T;
    T = readInt();
    while(T--)
    {
        n = readInt();
        vx.resize(n+5);
        pz.resize(n+5);
        noz.resize(n+5);
        memo.resize(n+5);   
        for(ll i=1;i<=n;i++)
        {
            ll m;
            m = readInt();
            vx[i].resize(m+5);
            pz[i].resize(m+5);
            memo[i].resize(m+5);
            noz[i] = m;
            for(ll j=1;j<=m;j++)
            {    
                vx[i][j] = readInt();
                memo[i][j] = 0;
            }    
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=noz[i];j++)
            {
                if(j == noz[i])
                pz[i][j] = mp(vx[i][1], vx[i][j]);
                else pz[i][j] = mp(vx[i][j+1], vx[i][j]);    
            }    
        }    
        ll ans = 0;
        for(ll i=1;i<n;i++) 
        {
            ll max1 = -1000000000000, max2 = -1000000000000;
            for(int j=1;j<=noz[i];j++) 
            {
                max1 = std::max(max1, memo[i][j] - i*pz[i][j].second);
                max2 = std::max(max2, memo[i][j] + i*pz[i][j].second);
            }
            for(int j=1;j<=noz[i+1];j++)
            memo[i+1][j] = std::max(memo[i+1][j], std::max(max1 + i*pz[i+1][j].first, max2 - i*pz[i+1][j].first));
        } 
        for(int i=1;i<=noz[n];i++)
        ans = std::max(ans, memo[n][i]);    
        printf("%lld\n", ans);
        for(ll i=1;i<=n;i++)
        {
            vx[i].clear();
            pz[i].clear();
            memo[i].clear();
        }    
        vx.clear();
        pz.clear();
        noz.clear();
        memo.clear();
    }
    return 0;
} 