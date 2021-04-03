#include <bits/stdc++.h>
#define mp std::make_pair
#define CHOR 300001

typedef long long ll;

ll arr[CHOR], pref[CHOR];
std::pair<ll, int> px[CHOR];

bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    return (a.first < b.first);
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        std::cin>>arr[i];
        px[i] = mp(arr[i], i);
    }    
    int k;
    std::cin>>k;
    std::sort(arr+1, arr+n+1);
    std::sort(px+1, px+n+1, cmp);
    for(int i=1;i<=n;i++)
    pref[i] = pref[i-1] + arr[i];
    int p1 = 1, p2 = 1;
    ll sx = 0;
    while(p2 <= k)
    {
        sx += ((arr[p2] * (p2-p1)) - (pref[p2-1] - pref[p1-1]));
        p2++;
    }    
    ll ans = sx;
    int s = p1, e = p2-1;
    while(p2 <= n)
    {
        sx -= ((pref[p2-1] - pref[p1]) - (arr[p1] * (p2-p1-1)));
        p1++;
        sx += ((arr[p2] * (p2-p1)) - (pref[p2-1] - pref[p1-1]));
        if(ans > sx)
        {
            ans = std::min(ans, sx);
            s = p1;
            e = p2;
        }
        p2++;
    }
    //std::cout<<ans<<"\n";
    for(int i=s;i<=e;i++)
    std::cout<<px[i].second<<" ";
    std::cout<<"\n";
    return 0;
}