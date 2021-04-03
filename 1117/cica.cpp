#include <bits/stdc++.h>

typedef long long ll;

int arr[16];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        ll n;
        int m;
        std::cin>>n>>m;
        for(int i=0;i<m;i++)
        std::cin>>arr[i];
        int ans = 0;
        for(int i=0;i<(1<<m);i++)
        {
            ll lc = 1;
            for(int j=0;j<m;j++)
            {
                if(i & (1<<j))
                lc = (lc * arr[j])/std::__gcd(lc, (1LL*arr[j]));
            }
            if(__builtin_popcount(i) & 1)
            ans -= n/lc;
            else ans += n/lc;
        }
        std::cout<<"Case "<<t<<": "<<ans<<"\n";
    }
    return 0;
}