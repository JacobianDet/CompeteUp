#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
    int n,d;
    std::cin>>n>>d;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    int p1 = 0, p2 = 2;
    ll ctx = 0;
    while(p2 < n)
    {
        if((p2 > p1 + 1) && (arr[p2] - arr[p1] <= d))
        {
            //std::cout<<(2*(p2 - p1) - 3)<<" "<<arr[p2] - arr[p1]<<"\n";
            ctx += (1LL*(p2-p1-1)*(p2-p1))/2;
            p2++;
        }
        else
        {
            if(p2 - p1 < 2)
            p2++;
            else p1++;
        }
    }
    std::cout<<ctx<<"\n";
    return 0;
}
