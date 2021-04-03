#include <bits/stdc++.h>

typedef long long ll;

ll arr[1001], ax[1000001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        std::sort(arr, arr+n);
        int t=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            ax[t++] = (arr[i] + arr[j]);
        }        
        std::sort(ax, ax+t);
        ll ans1 = 0;
        for(int i=0;i<t;i++)
        ans1 += 2*(i*ax[i] - (t-i-1)*ax[i]);
        ll ans2 = 0;
        for(int i=0;i<n;i++)
        ans2 += 2*(i*arr[i] - (n-i-1)*arr[i]);
        ans1 -= (n-2)*ans2;
        std::cout<<ans1<<"\n";
    }
    return 0;
}