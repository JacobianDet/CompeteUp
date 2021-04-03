#include <bits/stdc++.h>

typedef long long ll;

ll arr[1001];

ll bs2(int n, ll s)
{
    ll lo = 0;
    ll hi = *std::min_element(arr+1, arr+n);
    while(lo < hi)
    {
        ll mid = lo + (hi - lo + 1)/2;
        ll v = 0;
        for(int i=1;i<=n;i++)
        v += (arr[i] - mid);
        if(v >= s)
        lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main(void)
{
    int n;
    ll s;
    std::cin>>n>>s;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    ll z = 0;
    for(int i=1;i<=n;i++)
    z += arr[i];
    if(z < s)
    std::cout<<"-1\n";
    else
    {
       ll ans = bs2(n, s);
       std::cout<<ans<<"\n"; 
    }
    return 0;
}