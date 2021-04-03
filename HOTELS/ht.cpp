#include <bits/stdc++.h>
#define CHOR 300001

typedef long long ll;

ll arr[CHOR];

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    int p1 = 0, p2 = 0;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    ll sx = 0, ans = 0;
    while(p2 < n)
    {
        while((p1 < p2) && (sx + arr[p2] > m))
        {
            sx -= arr[p1];
            p1++;
        }
        if(sx + arr[p2] <= m)
        {
            sx += arr[p2];
            ans = std::max(ans, sx);
            p2++;
        }
        else
        {
            p1++;
            p2++;
        }
    }
    while(p1 < n)
    {
        sx -= arr[p1];
        ans = std::max(ans, sx);
        p1++;
    }
    std::cout<<ans<<"\n";
    return 0;
}